#include <string>
#include <vector>
#include <iostream>

using namespace std;

string solution(string number, int k) 
{
    string answer;
    
    for (char digit : number) 
    {
        while (!answer.empty() && k > 0 && answer.back() < digit) 
        {
            answer.pop_back();  // 작은 숫자 제거
            k--;
        }
        answer.push_back(digit);  // 현재 숫자 추가
    }
    
    // 아직 제거할 숫자가 남았다면 뒤에서 제거
    if (k > 0) {
        answer.erase(answer.size() - k);
    }

    return answer;
}