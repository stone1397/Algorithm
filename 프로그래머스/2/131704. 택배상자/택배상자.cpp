#include <string>
#include <vector>
#include <stack>

using namespace std;

int solution(vector<int> order) {
    int answer = 0;
    stack<int> sub_truck;
    // 비교를 위해 넣어둠
    sub_truck.push(0);
    int i = 0;
    int j = 1;
    
    while (i < order.size())
    {
        if (order[i] == j)
        {
            answer++;
            i++;
            j++;
        }
        else
        {
            if (order[i] == sub_truck.top())
            {
                sub_truck.pop();
                answer++;
                i++;
            }
            else if (order[i] < sub_truck.top()) break;
            else
            {
                sub_truck.push(j);
                j++;
            }    
        }
    }
    return answer;
}