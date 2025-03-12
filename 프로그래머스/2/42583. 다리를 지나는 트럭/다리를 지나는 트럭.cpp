#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) 
{
    int time = 0;             // 총 경과 시간
    int bridge_weight = 0;    // 현재 다리 위의 총 무게
    queue<pair<int, int>> bridgeTruck_queue; // (트럭 무게, 진입 시간)

    for (int truck : truck_weights)
    {
        while (true)
        {
            // 다리 위에 트럭이 있고, 맨 앞 트럭이 다리를 완전히 건넜다면 제거
            if (!bridgeTruck_queue.empty() && bridgeTruck_queue.front().second + bridge_length == time)
            {
                bridge_weight -= bridgeTruck_queue.front().first;
                bridgeTruck_queue.pop();
            }

            // 다리에 새 트럭을 올릴 수 있는 경우
            if (bridge_weight + truck <= weight)
            {
                bridgeTruck_queue.push({truck, time});
                bridge_weight += truck;
                break; // 트럭을 추가했으므로 다음 트럭으로 진행
            }

            // 트럭을 추가할 수 없으면 시간 증가
            time++;
        }
        
        // 트럭이 다리에 올라갈 때마다 시간 증가
        time++;
    }

    // 마지막 트럭이 다리를 건너는 데 걸리는 시간 추가
    return time + bridge_length;
}