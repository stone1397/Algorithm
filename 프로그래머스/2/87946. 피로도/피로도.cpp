#include <string>
#include <vector>

using namespace std;

int MaxCount = 0;

void ExploreDungeons(int K, vector<vector<int>>& Dungeons, vector<bool>& bVisited, int count)
{
    MaxCount = max(MaxCount, count);
    
    for (int i = 0; i < Dungeons.size(); i++)
    {
        if ( K >= Dungeons[i][0] && !bVisited[i])
        {
            bVisited[i] = true; // 방문
            ExploreDungeons( K - Dungeons[i][1], Dungeons, bVisited, count+1); // 재귀함수 호출
            bVisited[i] = false; // 조건에 맞지 않을 경우 원상복구
        }   
    }
}

int solution(int K, vector<vector<int>> Dungeons) {
    vector<bool> bVisitedVector(Dungeons.size(), false);
    ExploreDungeons(K, Dungeons, bVisitedVector, 0);
    int answer = -1;
    answer = MaxCount;
    return answer;
}