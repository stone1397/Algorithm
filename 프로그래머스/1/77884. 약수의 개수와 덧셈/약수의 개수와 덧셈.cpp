#include <string>
#include <vector>
#include <cmath>

using namespace std;

int solution(int left, int right) {
    int answer = 0;
    int start = ceil(sqrt(left));
    for (int i = left; i < right + 1; i++) {
        for (int j = start; j*j <= right; j++) {
            if (j*j == i) {
                answer -= 2*i;
            }
        }
    answer += i;
    }
    return answer;
}