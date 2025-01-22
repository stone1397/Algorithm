#include <string>
#include <vector>
#include <iostream>

using namespace std;

string solution(string s) {
    string answer = s;
    // 공백의 위치 찾기
    size_t pos = answer.find(' ');
    // 단어의 문자 변환
    if (!answer.empty() && answer[0] >= 'a' && answer[0] <= 'z')
    {
        answer[0] = toupper(answer[0]);
    }
    for (size_t i = 1; i < min(pos, answer.size()); i++)
    {
        if (answer[i] >= 'A' && answer[i] <= 'Z')
        {
            answer[i] = tolower(answer[i]);
        }
    }
    while(pos != string::npos)
    {
        // 이전 단어 자르기
        string rest = answer.substr(pos+1);
        // 자른 단어에서 또 공백의 위치 찾기
        size_t pos_two = rest.find(' ');
        // 단어의 문자 변환
        if (answer[pos+1] >= 'a' && answer[pos+1] <= 'z')
        {
           answer[pos+1] = toupper(answer[pos+1]);
        }
        // 만약 pos_two == string::npos일 경우 (마지막 문자), 탈출 조건
        if (pos_two == string::npos)
        {
            for (size_t i = 1; i < answer.size()-(pos+1); i++)
            {
                if (answer[pos+1+i] >= 'A' && answer[pos+1+i] <= 'Z')
                {
                answer[pos+1+i] = tolower(answer[pos+1+i]);
                }
            }
            break;
        }
        else  // 마지막 문자가 아닐 경우
        {
            for (size_t i = 1; i < pos_two; i++)
            {
                if (answer[pos+1+i] >= 'A' && answer[pos+1+i] <= 'Z')
                {
                    answer[pos+1+i] = tolower(answer[pos+1+i]);
                }
            }
        }
        // pos 값 다음 공백까지로 갱신
        pos = pos + 1 + pos_two;
    }
    
    return answer;
}