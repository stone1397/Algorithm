#include <string>
#include <vector>
#include <queue>
#include <unordered_map>
#include <algorithm>

using namespace std;

int bfs(int x, int y, int n)
{
    queue<pair<int, int>> q; 
    unordered_map<int, int> visited; // 방문한 숫자 & 최소 연산 횟수
    
    q.push({x, 0});
    visited[x] = 0;
    
    while(!q.empty())
    {
        int current = q.front().first;
        int count = q.front().second;
        q.pop();
        
        // 목표 도달 시 종료
        if (current == y) return count;
        
        // 가능한 연산
        int nextValues[3] = {current + n, current * 2, current * 3};
        
        for (int nextValue : nextValues)
        {
            if (nextValue <= y && visited.find(nextValue) == visited.end())
            {
                visited[nextValue] = count + 1;
                q.push({nextValue, count + 1});
            }
        }
    }
    return -1;
}

int solution(int x, int y, int n) 
{
    int answer = 0;
    answer = bfs(x, y, n);
    return answer;
}