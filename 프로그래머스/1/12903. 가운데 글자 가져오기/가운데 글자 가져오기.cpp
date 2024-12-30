#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    string answer = "";
    int half_length = s.length() / 2;
    if (s.length() % 2 == 0){
        answer.push_back(s[half_length - 1]);
        answer.push_back(s[half_length]);
    }
    else {
        answer.push_back(s[half_length]);
    }
    return answer;
}