#include <string>
#include <vector>

using namespace std;

void DFS(const vector<int>& Numbers, int Index, int CurrentSum, int Target, int& Answer) 
{
    if (Index == Numbers.size())
    {
        if (CurrentSum == Target)
        {
            Answer++;
        }
        return;
    }
    // 더하는 함수
    DFS(Numbers, Index+1, CurrentSum + Numbers[Index], Target, Answer);
    // 빼는 함수
    DFS(Numbers, Index+1, CurrentSum - Numbers[Index], Target, Answer);
}
int solution(vector<int> Numbers, int Target) {
    int Answer = 0;
    DFS(Numbers, 0, 0, Target, Answer);
    
    return Answer;
}