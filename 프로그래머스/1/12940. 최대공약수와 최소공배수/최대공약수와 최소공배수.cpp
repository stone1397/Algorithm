#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(int n, int m) {
    int min_value = min(n, m);
    int max_value = max(n, m);
    int gcd = 1;
    int lcm = 1;
    
    for (int i = 2; i <= min_value; i++) {
        if (n % i == 0 && m % i == 0 ) {
            gcd = i;
        }
    }
    
    for (int j = 1; j <= max_value; j ++) {
        int multivalue = min_value * j;
        if (multivalue >= max_value && multivalue % max_value == 0 ) {
            lcm = min_value * j;
            break;
        }
    }
    
    vector<int> answer;
    answer.push_back(gcd);
    answer.push_back(lcm);
    
    return answer;
}