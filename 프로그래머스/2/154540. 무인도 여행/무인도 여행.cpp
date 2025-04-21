#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

vector<int> solution(vector<string> maps) {
        int n = maps.size();        
    int m = maps[0].size();      
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    vector<int> answer;

    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};

   
    for(int i = 0; i < n; i++) 
    {
        for(int j = 0; j < m; j++) 
        {
           
            if(!visited[i][j] && maps[i][j] != 'X') 
            {
                queue<pair<int, int>> q;
                q.push({i, j});
                visited[i][j] = true;
                int totalDays = maps[i][j] - '0';

              
                while(!q.empty()) 
                {
                    int x = q.front().first;
                    int y = q.front().second;
                    q.pop();

                    for(int dir = 0; dir < 4; dir++) 
                    {
                        int nx = x + dx[dir];
                        int ny = y + dy[dir];

                        
                        if(nx >= 0 && nx < n && ny >= 0 && ny < m) 
                        {
                            if(!visited[nx][ny] && maps[nx][ny] != 'X') 
                            {
                                visited[nx][ny] = true;
                                totalDays += maps[nx][ny] - '0';
                                q.push({nx, ny});
                            }
                        }
                    }
                }
               
                answer.push_back(totalDays);
            }
        }
    }


    if(answer.empty()) 
    {
        answer.push_back(-1);
    } 
    else 
    {
        sort(answer.begin(), answer.end()); 
    }

    return answer;
}