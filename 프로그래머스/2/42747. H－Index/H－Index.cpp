#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> citations) {
    sort(citations.begin(), citations.end(), greater<int>()); // 내림차순 정렬
    int h = 0;
    
    for (int i = 0; i < citations.size(); i++) {
        if (citations[i] >= i + 1) { // h-index 조건 만족 여부 확인
            h = i + 1;
        } else {
            break; // h-index를 더 증가시킬 수 없으면 종료
        }
    }
    
    return h;
}