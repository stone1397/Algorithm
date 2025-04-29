#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

const int MAX_N = 14;
const int OFFSET = 14; // 중심점 보정
bool visited[2 * MAX_N + 1][2 * MAX_N + 1]; // (28x28) 범위
int N; // 이동 횟수
double prob[4]; // 동, 서, 남, 북 확률
double result = 0.0;

// 동서남북 이동 델타
int dx[4] = { 1, -1, 0, 0 }; // E, W, S, N
int dy[4] = { 0, 0, -1, 1 };

void dfs(int x, int y, int move_count, double current_prob) 
{
    if (move_count == N) 
    {
        result += current_prob;
        return;
    }

    for (int dir = 0; dir < 4; dir++) 
    {
        int nx = x + dx[dir];
        int ny = y + dy[dir];

        if (!visited[nx][ny] && prob[dir] > 0) 
        {
            visited[nx][ny] = true;
            dfs(nx, ny, move_count + 1, current_prob * prob[dir]);
            visited[nx][ny] = false; // 백트래킹
        }
    }
}

int main() 
{
    cin >> N;
    int p[4];
    for (int i = 0; i < 4; i++) 
    {
        cin >> p[i];
        prob[i] = p[i] / 100.0; // 퍼센트 → 소수 변환
    }

    visited[OFFSET][OFFSET] = true; // 시작 위치 방문 표시
    dfs(OFFSET, OFFSET, 0, 1.0);

    cout << fixed << setprecision(10) << result << endl;
    return 0;
}