#include <string>
#include <vector>

using namespace std;

vector<int> solution(string s) {
    bool same = true;
    vector<int> answer;
    answer.push_back(-1);
    for (int i = 1; i < s.length(); i++ ) {
        for (int j = i - 1; j >= 0; j--) {
            if (s[i] == s[j]) {
                answer.push_back(i - j);
                same = true;
                break;
            }
            else {
                same = false;
            }
            
        }
        if (!same) {
            answer.push_back(-1);
            same = true;
        }
    }
    return answer;
}