#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> diffs, vector<int> times, long long limit) {
    int answer = 1;
    long long Sum;
    while(true) {
        Sum = max(0, (diffs[0] - answer)) * (times[0]) + times[0];
        for (int i = 1; i < diffs.size(); i++) {
            Sum += max(0, (diffs[i] - answer)) * (times[i] + times[i - 1]) + times[i];
            if (Sum > limit) { 
                break;
            }
        }
        
        if (Sum <= limit) {
            break;
        }
        answer = answer + 2;
    }
   
    int prev_answer = max(1, answer -1);
    long long prev_sum = max(0, (diffs[0] - prev_answer)) * (times[0]) + times[0];
    
    for (int i = 1; i < diffs.size(); i++) {
        prev_sum += max(0, (diffs[i] - prev_answer)) * (times[i] + times[i - 1]) + times[i];
    }
    if (prev_sum <= limit) {
        return prev_answer;
    }
    else {
        return answer;
    }
    
}