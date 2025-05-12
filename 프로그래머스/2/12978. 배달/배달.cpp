#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9;

int solution(int N, vector<vector<int>> road, int K) 
{
    // 그래프 초기화
    vector<vector<pair<int,int>>> adj(N+1);
    for (auto& r : road) 
    {
        int u = r[0], v = r[1], w = r[2];
        adj[u].emplace_back(v, w);
        adj[v].emplace_back(u, w);
    }
    // 다익스트라
    vector<int> dist(N+1, INF);
    dist[1] = 0;
    priority_queue<pair<int,int>,
        vector<pair<int,int>>,
        greater<pair<int,int>>> pq;
    pq.emplace(0, 1);
    
    while (!pq.empty()) 
    {
        auto [d, u] = pq.top(); pq.pop();
        if (d > dist[u]) continue;
        for (auto& [v, w] : adj[u]) 
        {
            if (dist[v] > d + w) 
            {
                dist[v] = d + w;
                pq.emplace(dist[v], v);
            }
        }
    }
    // K 이하인 마을 개수 계산
    int answer = 0;
    for (int i = 1; i <= N; ++i)
        if (dist[i] <= K) ++answer;
    return answer;
}