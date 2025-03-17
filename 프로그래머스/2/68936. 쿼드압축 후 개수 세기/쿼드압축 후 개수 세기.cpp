#include <string>
#include <vector>

using namespace std;

void quadTree(int x, int y, int size, vector<vector<int>>& arr, vector<int>& answer)
{
    int first_value = arr[x][y];
    bool all_same = true;
    for (int i = x; i < x + size; i++)
    {
        for (int j = y; j < y + size; j++)
        {
            if (arr[i][j] != first_value)
            {
                all_same = false;
                break;
            }
        }
        if (!all_same) break;
    }
    if (all_same) answer[first_value]++;
    else
    {
        int half_size = size/2;
        quadTree(x, y, half_size, arr, answer);
        quadTree(x + half_size, y, half_size, arr, answer);
        quadTree(x, y + half_size, half_size, arr, answer);
        quadTree(x + half_size, y + half_size, half_size, arr, answer);
    }
    return;
}

vector<int> solution(vector<vector<int>> arr) {
    vector<int> answer = {0, 0};
    quadTree(0, 0, arr.size(), arr, answer);
    return answer;
}