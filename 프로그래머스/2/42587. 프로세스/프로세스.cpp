#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0;
    queue<pair<int, int>> ProcessQueue;
    priority_queue<int> PriorityQueue;
    
    for (int i = 0; i < priorities.size(); i++)
    {
        ProcessQueue.push({priorities[i], i});
        PriorityQueue.push(priorities[i]);
    }
    
    while (!ProcessQueue.empty())
    {
        int CurrentPriority = ProcessQueue.front().first;
        int CurrentIndex = ProcessQueue.front().second;
        ProcessQueue.pop();
        
        if (CurrentPriority == PriorityQueue.top())
        {
            answer++;
            PriorityQueue.pop();
            
            if (CurrentIndex == location)
            {
                return answer;
            }
        }
        else
        {
            ProcessQueue.push({CurrentPriority, CurrentIndex});
        }
    }
    
    return answer;
}