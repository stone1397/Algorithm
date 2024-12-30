#include <string>
#include <vector>

using namespace std;

int solution(vector<int> numbers) {
    int answer = 0;
    int sum = 45;
    int sum_numbers = 0;
    for (int num : numbers) {
        sum_numbers += num;
    }
    answer = sum - sum_numbers;
    return answer;
}