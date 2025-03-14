#include <string>
#include <vector>
#include <unordered_set>
#include <algorithm>
#include <cmath>

using namespace std;
// 소수 판별 함수
bool isPrime(int num) {
    if (num < 2) return false;
    for (int i = 2; i * i <= num; i++) 
    {
        if (num % i == 0) return false;
    }
    return true;
}

// 숫자 조합을 만들어 소수 개수를 구하는 함수
int solution(string numbers) 
{
    unordered_set<int> number_set;  // 중복 방지를 위해 set 사용
    int answer = 0;

    sort(numbers.begin(), numbers.end());

    // 가능한 모든 길이의 숫자 조합을 만든다.
    for (int i = 1; i <= numbers.size(); i++) 
    {
        vector<bool> perm(numbers.size(), false);
        fill(perm.begin(), perm.begin() + i, true);
        
        do 
        {
            string num_str = "";
            for (int j = 0; j < numbers.size(); j++) 
            {
                if (perm[j]) num_str += numbers[j];
            }
            sort(num_str.begin(), num_str.end());
            do {
                number_set.insert(stoi(num_str));
            } while (next_permutation(num_str.begin(), num_str.end()));
        } while (prev_permutation(perm.begin(), perm.end()));
    }

    // 소수 판별
    for (int num : number_set) 
    {
        if (isPrime(num)) answer++;
    }

    return answer;
}