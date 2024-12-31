#include <string>
#include <vector>
#include <cmath>

using namespace std;

int solution(int n) {
    int answer = 0;
    vector<int> base_three;
    while (true) {
        base_three.push_back(n % 3);
        n = n / 3;
        if(n == 0) {
            break;
        }
    }
    int multiplier = base_three.size()-1;
    for (int i = 0; i <= multiplier; i++ ) {
        answer += base_three[i] * pow(3, (multiplier - i));
    }
    return answer;
}