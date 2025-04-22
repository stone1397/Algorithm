#include <string>
#include <vector>
#include <climits>

using namespace std;

vector<int> solution(int rows, int columns, vector<vector<int>> queries) 
{
    vector<vector<int>> matrix(rows, vector<int>(columns));
    vector<int> answer;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            matrix[i][j] = columns * i + (j+1);
        }
    }
    for (auto& query : queries)
    {
        int x1 = query[0] - 1;
        int y1 = query[1] - 1;
        int x2 = query[2] - 1;
        int y2 = query[3] - 1;

        int temp = matrix[x1][y1];
        int minElement = temp;

        // 왼쪽 column 위로 이동
        for (int i = x1; i < x2; i++) 
        {
            matrix[i][y1] = matrix[i+1][y1];
            minElement = min(minElement, matrix[i][y1]);
        }

        // 아래쪽 row 왼쪽 이동
        for (int j = y1; j < y2; j++) 
        {
            matrix[x2][j] = matrix[x2][j+1];
            minElement = min(minElement, matrix[x2][j]);
        }

        // 오른쪽 column 아래로 이동
        for (int i = x2; i > x1; i--) 
        {
            matrix[i][y2] = matrix[i-1][y2];
            minElement = min(minElement, matrix[i][y2]);
        }

        // 위쪽 row 오른쪽 이동
        for (int j = y2; j > y1; j--) 
        {
            matrix[x1][j] = matrix[x1][j-1];
            minElement = min(minElement, matrix[x1][j]);
        }

        matrix[x1][y1+1] = temp;
        minElement = min(minElement, temp);

        answer.push_back(minElement);
    }
    
    return answer;
}