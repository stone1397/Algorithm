#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

string solution(string s, string skip, int index) {
    string answer = "";
    int KeyValue = 0;
    // skip에 있는 문자를 제외하고 모든 알파벳을 map에 저장하기
    unordered_map<char, int> AlphabetToNum;
    unordered_map<int, char> NumToAlphabet;
    for(char c = 'a'; c <= 'z'; c++)
    {
        // skip에 문자가 없는 경우 -> map에 추가
        if(skip.find(c) == string::npos)
        {
            AlphabetToNum.emplace(c, KeyValue);
            NumToAlphabet.emplace(KeyValue, c);
            KeyValue++;
        }
    }
    
    // 문자의 index만큼 뒤의 문자로 변환
    for(char c : s)
    {
        // 모듈로 연산으로 value 갱신
        int Value = (AlphabetToNum[c] + index) % AlphabetToNum.size();
        
        // 찾은 value로 key 찾아 넣기
        answer.push_back(NumToAlphabet[Value]);
    }
    
    
    return answer;
}