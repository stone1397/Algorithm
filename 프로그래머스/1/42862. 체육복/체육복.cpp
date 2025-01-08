#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    
    for (auto it = lost.begin(); it != lost.end();) {
        auto found = find(reserve.begin(), reserve.end(), *it);
        if (found != reserve.end()) {
            // 겹치는 경우 reserve와 lost에서 제거
            reserve.erase(found);
            it = lost.erase(it);
        } else {
            ++it;
        }
    }
    
    
    // 빌린 사람 카운트
    sort(lost.begin(), lost.end());
    sort(reserve.begin(), reserve.end());
    int count = 0;
    int answer = 0;
    for (int num : reserve)
    {
        // lost에 있는 지 요소 찾기: 작은 수부터
        auto it = find(lost.begin(), lost.end(), num-1);
        if (it == lost.end())
        {
            it = find(lost.begin(), lost.end(), num+1);
            if (it != lost.end())
            {
                *it = -1;
                count++;
            }
        }
        else
        {
            // 찾은 원소를 -1로 바꾸어 표시해주기, 반복적으로 찾기 방지
            *it = -1;
            count++;
        }
    }
    
    // 전체 - 잃어버린 사람 + 빌려준 사람
    answer = n - lost.size() + count;
    
    return answer;
}