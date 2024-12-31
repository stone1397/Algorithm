#include <string>
#include <vector>

using namespace std;

int solution(string t, string p) {
    int answer = 0;
    for (int i = 0; i < t.size()-p.size() +1; i++) {
        int j = i;
        while(j < p.size() + i) {
            if (t[j] == p[j-i]) {
                j++;
            }
            else if(t[j] > p[j-i]) {
                break;
            }
            else {
                answer++;
                break;
            }
        if (j == p.size() + i)
            answer++;
        }
    }
    
    return answer;
}