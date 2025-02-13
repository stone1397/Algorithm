#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    vector<int> times(speeds.size());
    int max_element;
    int distribution_count = 1;
    
    // 시간에 대한 벡터
    for (int i = 0; i < speeds.size(); i++)
    {
        if (((100 - progresses[i]) % speeds[i]) == 0)
        {
            times[i] = ((100 - progresses[i]) / speeds[i]);
        }
        else
        {
            times[i] = ((100 - progresses[i]) / speeds[i]) + 1;
        }
    }
    /*
    // 로그 찍기
    for (int time : times)
    {
        cout << time << " , " ;
    }
    */
    
    
    max_element = times[0];
    // 시간 벡터를 이용해서 answer 구하기
    for (int i = 1; i < times.size(); i++)
    {
        if (times[i] > max_element)
        {
            answer.push_back(distribution_count);
            max_element = times[i];
            distribution_count = 1;
            if (i == times.size()-1)
            {
                answer.push_back(distribution_count);
               
            }
        }
        else
        {
            distribution_count++;
            if (i == times.size()-1)
            {
                answer.push_back(distribution_count);
                
            }
        }
    }
    return answer;
}