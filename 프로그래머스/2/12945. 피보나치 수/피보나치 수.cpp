#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 1;
    int previous_answer = 1;
    if (n > 2)
    {
        for (int i = 3; i <= n ; i++)
        {
           int temp = answer; 
           answer = (answer + previous_answer) % 1234567;
           previous_answer = temp;
        } 
    }
    return answer;
}