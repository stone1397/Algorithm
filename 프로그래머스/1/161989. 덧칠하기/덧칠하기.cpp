#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(int n, int m, vector<int> section)
{
	int answer = 0;
	vector<int> finish;

	int next_start = 0;
	int paint_last = 10;

    if (section.size() == 1)
        return 1;

	// 페인트 칠 맨 마지막 (section[section.size()-1] 시작)
	for (int i = section.size() - 2; i >= 0; i--)
	{
		if (section[section.size() - 1] - (m - 1) > section[i])
		{
			paint_last = i;
			break;
		}
		// 한 번에 모두 칠했을 경우
        else if (section[section.size() - 1] - (m - 1) <= section[0])
		{
			return 1;
		}
	}
	answer++;

	// paint_last 까지 계속 칠하기
	while (next_start <= paint_last)
	{
		for (int i = next_start + 1; i < section.size(); i++)
		{
			if (section[next_start] + (m - 1) < section[i])
			{
				next_start = i;
				break;
			}
		}
		answer++;
		
	}

	return answer;
}

