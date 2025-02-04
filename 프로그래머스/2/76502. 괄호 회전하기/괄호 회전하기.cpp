#include <iostream>
#include <stack>

using namespace std;

bool isValid(const string& s, int start, int length)
{
	stack<char> bracketSt;
    for (int i = start; i < start + length; i++)
    {
        char c = s[i%length];
        if ( c == '(' || c =='{' || c == '[')
        {
            bracketSt.push(c); // 여는 괄호일 경우 push
        }
        else
        {
            if (bracketSt.empty()) { return false; } // 여는 괄호 없이 닫는 괄호가 나올 경우
            char top = bracketSt.top(); // 닫는 괄호일 경우 맨 위 접근
            if (( c == ')' && top == '(') ||
                ( c == '}' && top == '{') ||
                ( c == ']' && top == '['))   { bracketSt.pop();} // 짝이 맞을 경우 제거
            else { return false; }
        }
    }
    return bracketSt.empty(); // 최종적으로 스택이 비어있을 때 true를 반환
}
               
               
int solution(string s) {
    int answer = 0;
    int length = s.length();
    
    // 시작 지점을 바꿔가며 검사
    for (int i = 0; i < length; i++)
    {
        if (isValid(s, i, length))
        {
            answer++;
        }
    }
    
    return answer;
}