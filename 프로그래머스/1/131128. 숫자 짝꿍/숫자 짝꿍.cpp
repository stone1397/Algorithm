#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

bool compare(char a, char b)
{
    return a > b;
}	

string solution(string X, string Y) {
    string answer = "";
    
    // 0~9까지의 빈도를 저장할 배열
    vector<int> freqX(10, 0);
    vector<int> freqY(10, 0);
    
    for (char c : X)
    {
    	freqX[c-'0']++;
    }
    for (char c : Y)
    {
    	freqY[c-'0']++;
    }
    
    //공통된 문자를 찾고 결과를 문자열에 추가
    for (int i = 9; i >=0; i--)
    {
    	int count = min(freqX[i], freqY[i]);
    	answer.append(string(count, i + '0'));
    }
    
    // 예외 처리
    if (answer.empty())
    {
    	return "-1";
    }
    if (answer[0] == '0')
    {
    	return "0";
    }
    return answer;

}