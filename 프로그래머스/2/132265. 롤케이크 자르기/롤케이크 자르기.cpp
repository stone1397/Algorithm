#include <vector>
#include <unordered_map>

using namespace std;

int solution(vector<int> topping) {
    int answer = 0;

    unordered_map<int, int> leftToppingCount, rightToppingCount;

    // 모든 토핑을 rightToppingCount에 저장
    for (int t : topping) 
    {
        rightToppingCount[t]++;
    }

    // leftToppingCount과 rightToppingCount의 개수를 비교하면서 순회
    for (int i = 0; i < topping.size() - 1; i++) 
    {
        int currentTopping = topping[i];

        // 왼쪽 조각에 현재 토핑 추가
        leftToppingCount[currentTopping]++;
        
        // 오른쪽 조각에서 현재 토핑 제거
        if (--rightToppingCount[currentTopping] == 0) 
        {
            rightToppingCount.erase(currentTopping);
        }

        // 왼쪽과 오른쪽의 서로 다른 토핑 개수가 같다면 공평하게 나눌 수 있음
        if (leftToppingCount.size() == rightToppingCount.size()) 
        {
            answer++;
        }
    }

    return answer;
}