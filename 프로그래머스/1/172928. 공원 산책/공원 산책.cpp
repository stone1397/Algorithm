#include <string>
#include <vector>
#include <sstream>
#include <iostream>

using namespace std;

void Move(const string& route, vector<string> park, vector<int>& current_location)
{
	char direction; //이동 방향
	int distance; // 이동 거리
	// current_location[0]-> y좌표, current_loctaion[1]-> x좌표
	// 현재 위치 park[current_location[0]][current_location[1]]
	bool bIsBlock = false;
	bool bGetOutRange = false;
	std::istringstream ss(route);
	ss >> direction >> distance;
	
	if (direction == 'E')
	{
		// 범위를 벗어나는 경우
		if (park[0].size() <= current_location[1] + distance)
		{
			bGetOutRange = true;
		}
		else
		{
			// 장애물이 있는 경우
			for (int i = 1; i < distance + 1; i++)
			{
				if (park[current_location[0]][current_location[1]+ i] == 'X')
				{
					bIsBlock = true;
				}
			}
		}
		// 장애물이 없고 범위를 벗어나지 않으면 이동
		if (!bIsBlock && !bGetOutRange)
		{
			current_location[1] += distance;
		}
	}
	if (direction == 'W')
	{
		
		// 범위를 벗어나는 경우
		if (current_location[1] - distance < 0 )
		{
			bGetOutRange = true;
		}
		else
		{
			// 장애물이 있는 경우
			for (int i = 1; i < distance + 1; i++)
			{
				if (park[current_location[0]][current_location[1]- i] == 'X')
				{
					bIsBlock = true;
				}
			}
		}
		
		// 장애물이 없고 범위를 벗어나지 않으면 이동
		if (!bIsBlock && !bGetOutRange)
		{
			current_location[1] -= distance;
			
		}
	}
	if (direction == 'S')
	{
		// 범위를 벗어나는 경우
		if (park.size() <= current_location[0] + distance )
		{
			bGetOutRange = true;
		}
		else
		{
			// 장애물이 있는 경우
			for (int i = 1; i < distance + 1; i++)
			{
				if (park[current_location[0]+i][current_location[1]] == 'X')
				{
					bIsBlock = true;
				}
			}
		}
		// 장애물이 없고 범위를 벗어나지 않으면 이동
		if (!bIsBlock && !bGetOutRange)
		{
			current_location[0] += distance;
		}
	}
	if (direction == 'N')
	{
		// 범위를 벗어나는 경우
		if (current_location[0] - distance < 0 )
		{
			bGetOutRange = true;
		}
		else
		{
			// 장애물이 있는 경우
			for (int i = 1; i < distance + 1; i++)
			{
				if (park[current_location[0]-i][current_location[1]] == 'X')
				{
					bIsBlock = true;
				}
			}
		}
		
		// 장애물이 없고 범위를 벗어나지 않으면 이동
		if (!bIsBlock && !bGetOutRange)
		{
			current_location[0] -= distance;
			
		
		}
	}
}


	

vector<int> solution(vector<string> park, vector<string> routes) {
    vector<int> answer = {0, 0};
    
    // 시작점을 찾는 함수
    for (int i = 0; i < park.size(); i++)
    {
        for (int j = 0; j < park[i].size(); j++)
        {
            if (park[i][j] == 'S')
            {
                answer[0] = i;
                answer[1] = j;
            }
        }
    }
    
    for (const string& route : routes)
    {
        Move(route, park, answer);
    }
    
    return answer;
}