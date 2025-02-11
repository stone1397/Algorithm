#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;

int solution(vector<string> want, vector<int> number, vector<string> discount) {
    int answer = 0;
    int StartIndex = 0;
    bool bIsCorrect;
    unordered_map<string, int> WantMap;
    unordered_map<string, int> CheckMap;
    // 맵에 원하는 품목의 이름, 수량 추가
    for (int i = 0; i < want.size(); i++)
    {
        WantMap[want[i]] = number[i]; 
    }
    while(StartIndex <= discount.size()-10)
    {
        CheckMap = WantMap;
        for (int j = StartIndex ; j < StartIndex + 10; j++)
        {
            
            bIsCorrect = true;
            // 10일 내에 찾는 물건이 없을 경우
            if (CheckMap.find(discount[j]) == CheckMap.end())
            {
                bIsCorrect = false;
                break;
            }
            // 10일 내에 찾는 물건이 필요한 것보다 더 많이 있는 경우
            else if (CheckMap[discount[j]] <= 0)
            {
                bIsCorrect = false;
                break;
            }
            // 둘 다 아닌 경우 수량을 하나 뺌
            else
            {
                CheckMap[discount[j]]--;

            }
        }
        if (bIsCorrect)
        {
            answer++;


        }
        StartIndex++;
    }
    return answer;
}