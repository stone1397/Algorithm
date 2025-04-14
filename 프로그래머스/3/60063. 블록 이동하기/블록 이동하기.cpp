#include <bits/stdc++.h>
using namespace std;

struct State {
    int x1, y1, x2, y2;
};

int solution(vector<vector<int>> board) {
    int N = board.size();
    // 방문 여부 체크 (두 좌표 순서 상관없이 동일한 상태로 처리)
    static bool visited[101][101][101][101];
    memset(visited, 0, sizeof(visited));

    // BFS 큐: (상태, 이동 횟수)
    deque<pair<State,int>> q;
    State start = {0, 0, 0, 1};
    q.push_back({start, 0});
    visited[0][0][0][1] = true;
    visited[0][1][0][0] = true;  // 두 칸 순서 바꾼 경우도 방문 표시

    // 방향 이동 배열 (상, 하, 좌, 우)
    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, -1, 1};

    while (!q.empty()) 
    {
        auto [cur, dist] = q.front();
        q.pop_front();
        int x1 = cur.x1, y1 = cur.y1;
        int x2 = cur.x2, y2 = cur.y2;
        // 목표 지점 도달 확인 (두 칸 중 하나라도 (N-1,N-1)인 경우)
        if ((x1 == N-1 && y1 == N-1) || (x2 == N-1 && y2 == N-1)) 
        {
            return dist;
        }

        // 1. 상하좌우 이동
        for (int i = 0; i < 4; ++i) 
        {
            int nx1 = x1 + dx[i], ny1 = y1 + dy[i];
            int nx2 = x2 + dx[i], ny2 = y2 + dy[i];
            // 격자 범위 체크
            if (nx1 < 0 || nx1 >= N || ny1 < 0 || ny1 >= N) continue;
            if (nx2 < 0 || nx2 >= N || ny2 < 0 || ny2 >= N) continue;
            // 벽 체크
            if (board[nx1][ny1] == 1 || board[nx2][ny2] == 1) continue;
            // 방문 체크 (두 좌표 순서 무관하게 표시)
            if (!visited[nx1][ny1][nx2][ny2]) 
            {
                visited[nx1][ny1][nx2][ny2] = true;
                visited[nx2][ny2][nx1][ny1] = true;
                q.push_back({{nx1, ny1, nx2, ny2}, dist + 1});
            }
        }

        // 2. 회전 (현재 가로 또는 세로 여부에 따라 처리)
        if (x1 == x2) 
        {
            // 현재 가로 방향인 경우
            // 위쪽으로 회전 가능 여부 체크
            if (x1 - 1 >= 0 && board[x1-1][y1] == 0 && board[x2-1][y2] == 0) 
            {
                // 왼쪽 칸을 축으로 위쪽 회전
                int nx1 = x1 - 1, ny1 = y1;
                int nx2 = x1, ny2 = y1;
                if (!visited[nx1][ny1][nx2][ny2]) 
                {
                    visited[nx1][ny1][nx2][ny2] = true;
                    visited[nx2][ny2][nx1][ny1] = true;
                    q.push_back({{nx1, ny1, nx2, ny2}, dist + 1});
                }
                // 오른쪽 칸을 축으로 위쪽 회전
                nx1 = x2 - 1; ny1 = y2;
                nx2 = x2; ny2 = y2;
                if (!visited[nx1][ny1][nx2][ny2]) 
                {
                    visited[nx1][ny1][nx2][ny2] = true;
                    visited[nx2][ny2][nx1][ny1] = true;
                    q.push_back({{nx1, ny1, nx2, ny2}, dist + 1});
                }
            }
            // 아래쪽으로 회전 가능 여부 체크
            if (x1 + 1 < N && board[x1+1][y1] == 0 && board[x2+1][y2] == 0) 
            {
                // 왼쪽 칸을 축으로 아래쪽 회전
                int nx1 = x1, ny1 = y1;
                int nx2 = x1 + 1, ny2 = y1;
                if (!visited[nx1][ny1][nx2][ny2]) 
                {
                    visited[nx1][ny1][nx2][ny2] = true;
                    visited[nx2][ny2][nx1][ny1] = true;
                    q.push_back({{nx1, ny1, nx2, ny2}, dist + 1});
                }
                // 오른쪽 칸을 축으로 아래쪽 회전
                nx1 = x2; ny1 = y2;
                nx2 = x2 + 1; ny2 = y2;
                if (!visited[nx1][ny1][nx2][ny2]) 
                {
                    visited[nx1][ny1][nx2][ny2] = true;
                    visited[nx2][ny2][nx1][ny1] = true;
                    q.push_back({{nx1, ny1, nx2, ny2}, dist + 1});
                }
            }
        } 
        else if (y1 == y2) 
        {
            // 현재 세로 방향인 경우
            // 왼쪽으로 회전 가능 여부 체크
            if (y1 - 1 >= 0 && board[x1][y1-1] == 0 && board[x2][y2-1] == 0) 
            {
                // BUG FIX: 좌우 회전도 양쪽 칸 모두 확인하도록 수정
                // 위쪽 칸을 축으로 왼쪽 회전
                int nx1 = x1, ny1 = y1 - 1;
                int nx2 = x1, ny2 = y1;
                if (!visited[nx1][ny1][nx2][ny2]) 
                {
                    visited[nx1][ny1][nx2][ny2] = true;
                    visited[nx2][ny2][nx1][ny1] = true;
                    q.push_back({{nx1, ny1, nx2, ny2}, dist + 1});
                }
                // 아래쪽 칸을 축으로 왼쪽 회전
                nx1 = x2; ny1 = y2 - 1;
                nx2 = x2; ny2 = y2;
                if (!visited[nx1][ny1][nx2][ny2]) 
                {
                    visited[nx1][ny1][nx2][ny2] = true;
                    visited[nx2][ny2][nx1][ny1] = true;
                    q.push_back({{nx1, ny1, nx2, ny2}, dist + 1});
                }
            }
            // 오른쪽으로 회전 가능 여부 체크
            if (y1 + 1 < N && board[x1][y1+1] == 0 && board[x2][y2+1] == 0) 
            {
                // 위쪽 칸을 축으로 오른쪽 회전
                int nx1 = x1, ny1 = y1;
                int nx2 = x1, ny2 = y1 + 1;
                if (!visited[nx1][ny1][nx2][ny2]) 
                {
                    visited[nx1][ny1][nx2][ny2] = true;
                    visited[nx2][ny2][nx1][ny1] = true;
                    q.push_back({{nx1, ny1, nx2, ny2}, dist + 1});
                }
                // 아래쪽 칸을 축으로 오른쪽 회전
                nx1 = x2; ny1 = y2;
                nx2 = x2; ny2 = y2 + 1;
                if (!visited[nx1][ny1][nx2][ny2]) 
                {
                    visited[nx1][ny1][nx2][ny2] = true;
                    visited[nx2][ny2][nx1][ny1] = true;
                    q.push_back({{nx1, ny1, nx2, ny2}, dist + 1});
                }
            }
        }
    }
    return -1;
}