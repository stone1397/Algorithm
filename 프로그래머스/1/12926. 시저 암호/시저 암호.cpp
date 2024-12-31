#include <string>
#include <vector>

using namespace std;

string solution(string s, int n) {
    string answer = "";
    answer = s; 
    for (int i = 0; i < answer.size(); i++) {
        if (answer[i] >= 'a' && answer[i] <= 'z') {
            answer[i] = ((answer[i] - 'a') + n) % 26 + 'a'; 
            if(answer[i] > 'z') {
                answer[i] = answer[i] - 26;
            }
        }
        
        else if (answer[i] >= 'A' && answer[i] <= 'Z') {
            answer[i] = ((answer[i] - 'A') + n) % 26 + 'A'; 
            if(answer[i] > 'Z') {
                answer[i] = answer[i] - 26;
            } 
        }
        else 
            answer[i] = answer[i];
    }
    
    return answer;
}