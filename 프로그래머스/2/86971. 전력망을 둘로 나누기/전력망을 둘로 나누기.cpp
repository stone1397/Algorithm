#include <vector>
#include <queue>
#include <cmath>
#include <algorithm>
using namespace std;

int solution(int n, vector<vector<int>> wires) 
{
    // 1. 인접 리스트 구성
    vector<vector<int>> adj(n + 1);
    for (auto &w : wires) 
    {
        int u = w[0], v = w[1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    int answer = n;  // 최대 차이는 n-2 vs 2 → n-4지만 안전하게 n으로 초기화
    // 2. 간선 하나씩 제거하며 탐색
    for (auto &w : wires) 
    {
        int u = w[0], v = w[1];
        // 간선 제거
        adj[u].erase(find(adj[u].begin(), adj[u].end(), v));
        adj[v].erase(find(adj[v].begin(), adj[v].end(), u));
        
        // BFS로 한 쪽 트리 크기 계산
        vector<bool> visited(n + 1, false);
        queue<int> q;
        q.push(u);
        visited[u] = true;
        int cnt = 0;
        while (!q.empty()) 
        {
            int cur = q.front(); q.pop();
            cnt++;
            for (int nxt : adj[cur]) 
            {
                if (!visited[nxt]) 
                {
                    visited[nxt] = true;
                    q.push(nxt);
                }
            }
        }
        // 두 트리 크이 차이 계산
        answer = min(answer, abs(cnt - (n - cnt)));
        
        // 간선 복원
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    return answer;
}