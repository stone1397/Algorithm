#include <string>
#include <vector>
#include <unordered_map>

using namespace std;


int solution(string s) {
    unordered_map<string, int> wordToNumber = {
        {"zero", 0}, {"one", 1}, {"two", 2}, {"three", 3},
        {"four", 4}, {"five", 5}, {"six", 6},
        {"seven", 7}, {"eight", 8}, {"nine", 9}
    };
    
    // 숫자 저장
    vector<int> numbers;
    // 단어 추가
    string currentWord;
    
    for (char c : s) {
        if( c >= '0' && c <= '9') {
            numbers.push_back(c - '0');
        }
        else {
            currentWord += c; //벡터를 순회하며 문자를 하나씩 추가
            if (wordToNumber.find(currentWord) != wordToNumber.end()) {
                numbers.push_back(wordToNumber[currentWord]); // 해당 키의 값을 추가해서 단어를 숫자로 변화하는 작업
                currentWord.clear(); // 다음 단어를 받기 위해 단어 초기화
            }
        }

    }
    
    // 숫자 배열을 숫자로 변환
    int answer = 0;
    for (int num : numbers) {
        answer = answer * 10 + num;
    }
    
    return answer;
}