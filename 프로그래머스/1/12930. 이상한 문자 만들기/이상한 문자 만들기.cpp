#include <string>
#include <vector>


using namespace std;

string solution(string s) {
    string answer = "";
    answer = s;
    int word_index = 0;
    int i = 0;
    while(i != answer.size()) {
        
        if(answer[i] == ' ') {
            word_index = 0;
        }
        else {
            if (word_index % 2 == 0) {
            answer[i] = toupper(answer[i]);
        }
        else {
            answer[i] = tolower(answer[i]);
        }
        word_index ++;
        }
        i ++;
    }

    return answer;
}