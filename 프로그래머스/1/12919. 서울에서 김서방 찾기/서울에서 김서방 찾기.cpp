#include <string>
#include <vector>

using namespace std;

string solution(vector<string> seoul) {
    int location;
    for( int i = 0; i < seoul.size(); i++) {
        if(seoul[i] == "Kim") {
            location = i;
            break;
        }
    }
    
    string answer = "김서방은 " + to_string(location) + "에 있다";
    return answer;
}