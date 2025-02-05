#include <string>
#include <vector>
#include <iostream>
#include <unordered_set>

using namespace std;

int solution(vector<int> elements) {
    int answer = 0;
    int SumCount = 1;
    int Size = elements.size();
    unordered_set<int> SumSet;
    while(SumCount < Size + 1)
    {
        int Start = 0;
        while( Start < Size)
        {
            int Sum = 0;
            for (int i = Start; i < Start + SumCount; i++)
            {
            	Sum += elements[i%Size];
            }
            SumSet.emplace(Sum);
            Start++;
        }
        SumCount++;    
    }
    answer = SumSet.size();

    return answer;
}