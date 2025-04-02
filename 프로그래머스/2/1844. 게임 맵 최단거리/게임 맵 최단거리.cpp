#include<vector>
#include<queue>
using namespace std;

int solution(vector<vector<int> > maps)
{
    int answer = 0;

    int n = maps.size();
    int m = maps[0].size();
    vector<vector<int>> direction = { {1,0}, {-1,0}, {0,1}, {0,-1} };
    queue<pair<int, int>> coordinate;
    
    // 0,0 시작
    coordinate.push({ 0, 0 });
    
    //// 도착지에 갈 수 없는 경우
    //if (maps[maps.size() - 2][maps[1].size() - 1] == 0 && maps[maps.size() - 1][maps[1].size() - 2] == 0)
    //{
    //    return -1;
    //}

    // 전후좌우 이동
    while (!coordinate.empty())
    {
        int x = coordinate.front().first;
        int y = coordinate.front().second;
        coordinate.pop();

        for (int i = 0; i < 4; i++)
        {
            int nx = x + direction[i][0];
            int ny = y + direction[i][1];

            // 범위 밖이거나 벽일 경우
            if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
            if (maps[nx][ny] != 1) continue;

            // 이동 가능한 경우
            maps[nx][ny] = maps[x][y] + 1;  // 거리 누적
            coordinate.push({ nx, ny });
        }
    }

    answer = maps[n-1][m-1];

    return answer == 1 ? -1 : answer;
}