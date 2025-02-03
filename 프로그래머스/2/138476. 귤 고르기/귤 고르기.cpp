#include <string>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

int solution(int k, vector<int> tangerine) {
    int answer = 0;
    unordered_map<int, int> SizeToNum;
    priority_queue<pair<int, int>> MaxHeap;
    for (int size : tangerine)
    {
        // 해당 사이즈가 map에 존재하지 않을 경우 -> 등록 후 개수 = 1
        if (SizeToNum.find(size) == SizeToNum.end())
        {
            SizeToNum.emplace(size, 1);
        }
        // 해당 사이즈에 map에 존재할 경우 -> 개수 증가
        else
        {
            SizeToNum[size]++;
        }
    }
    for (const auto& pair : SizeToNum) {
        MaxHeap.emplace(pair.second, pair.first);
    }
    if (k >= 1)
    {
        answer = 1;
        
        while(!SizeToNum.empty())
        {
            
            auto [MaxValue, MaxKey] = MaxHeap.top();  // 최댓값을 가진 요소 가져오기
            MaxHeap.pop(); // 최대 요소 제거
            // k와 비교
            if (MaxValue >= k)
            {
                break;
            }
            else
            {
                k = k - MaxValue;
                answer++;
            }
        }
        
    }
    
    
    return answer;
}