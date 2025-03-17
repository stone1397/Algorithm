#include <string>
#include <vector>

using namespace std;



void solveNQueens(vector<vector<bool>>& board, int row, vector<bool>& col, vector<bool>& diag1, vector<bool>& diag2, int n, int& solutionCount)
{
    // 모든 행에 퀸을 배치한 경우
    if (row == n) 
    {
       //printBoard(board);
        solutionCount++;
        return;
    }
    // 현재 행의 각 열을 순회하여 퀸을 놓을 수 있는지 확인
    for (int i = 0; i < n; i++)
    {
        if (!col[i] && !diag1[row - i + n - 1] && !diag2[row + i])
        {
            board[row][i] = true;
            col[i] = true;
            diag1[row - i + n - 1] = true;
            diag2[row + i] = true;
            
            // 다음 행으로 진행
            solveNQueens(board, row + 1, col, diag1, diag2, n, solutionCount);
            
            // 배치한 퀸을 제거(백트래킹)
            board[row][i] = false;
            col[i] = false;
            diag1[row- i + n - 1] = false;
            diag2[row + i] = false;
        }
    }
}

int solution(int n) 
{
    vector<vector<bool>> board(n, vector<bool>(n, false));
    vector<bool> col(n, false);
    vector<bool> diag1(2 * n - 1, false);
    vector<bool> diag2(2 * n - 1, false);
    int answer = 0;
    solveNQueens(board, 0, col, diag1, diag2, n, answer);
    return answer;
}