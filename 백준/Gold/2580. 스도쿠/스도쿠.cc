#include <iostream>
#include <vector>
using namespace std;

int board[9][9];
vector<pair<int, int>> blanks;

// 현재 위치 (row, col)에 number를 놓을 수 있는지 검사
bool isValid(int row, int col, int number) 
{
    // 같은 행 검사
    for (int i = 0; i < 9; i++) 
    {
        if (board[row][i] == number) return false;
    }

    // 같은 열 검사
    for (int i = 0; i < 9; i++) 
    {
        if (board[i][col] == number) return false;
    }

    // 같은 3x3 박스 검사
    int startRow = (row / 3) * 3;
    int startCol = (col / 3) * 3;
    for (int i = startRow; i < startRow + 3; i++) 
    {
        for (int j = startCol; j < startCol + 3; j++) 
        {
            if (board[i][j] == number) return false;
        }
    }
    return true;
}

// 백트래킹 함수
bool solve(int idx) 
{
    // 종료 조건 (모든 빈칸에 숫자 배치)
    if (idx == blanks.size()) 
    {
        return true;
    }

    int row = blanks[idx].first;
    int col = blanks[idx].second;

    for (int num = 1; num <= 9; num++) 
    {
        if (isValid(row, col, num)) 
        {
            board[row][col] = num;
            if (solve(idx + 1)) return true;
            board[row][col] = 0; // 실패 시 백트래킹
        }
    }

    return false;
}

int main() 
{
    // 입력 받기
    for (int i = 0; i < 9; i++) 
    {
        for (int j = 0; j < 9; j++) 
        {
            cin >> board[i][j];
            if (board[i][j] == 0) 
            {
                blanks.push_back({ i, j });
            }
        }
    }
    solve(0);

    // 결과 출력
    for (int i = 0; i < 9; i++) 
    {
        for (int j = 0; j < 9; j++) 
        {
            cout << board[i][j] << ' ';
        }
        cout << '\n';
    }

    return 0;
}
