#include <vector>
using namespace std;

vector<int> solution(int n) 
{
    vector<vector<int>> triangle(n);
    for (int i = 0; i < n; ++i) 
    {
        triangle[i].resize(i + 1, 0);
    }
		// 이동 방향 ( 아래 -> 오른쪽 -> 왼쪽 위 대각선 )
    vector<pair<int, int>> directions = { {1, 0}, {0, 1}, {-1, -1} }; 
    // 초기 가로, 세로, 방향
    int x = 0, y = 0, d = 0;
    int num = 1, maxNum = n * (n + 1) / 2;

    while (num <= maxNum) 
    {
        // 숫자 추가
        triangle[x][y] = num++;
        // 방향에 따라 x, y 값 변경
        int nx = x + directions[d].first;
        int ny = y + directions[d].second;
				
				// 변경된 x, y 값이 범위를 넘었을 경우 또는 이미 채워졌을 경우
        if (nx < 0 || nx >= n || ny < 0 || ny > nx || triangle[nx][ny] != 0) 
        {
		        // 방향 전환 후 대입
            d = (d + 1) % 3;
            x += directions[d].first;
            y += directions[d].second;
        } else 
        {
            x = nx;
            y = ny;
        }
    }

    vector<int> answer;
    for (const auto& row : triangle) 
    {
        for (int val : row) 
        {
            answer.push_back(val);
        }
    }

    return answer;
}