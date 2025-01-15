#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;

vector<string> solution(vector<string> players, vector<string> callings) {
    vector<string> answer;
    unordered_map<string, int> PlayersToRank;
    unordered_map<int, string> RankToPlayers;
    
    // 선수들의 현재 정보 저장
    for (int i = 0; i < players.size(); i++)
    {
        PlayersToRank.emplace(players[i], i+1);
        RankToPlayers.emplace(i+1, players[i]);
    }
    
    // 추월 시 정보 갱신
    for (int i = 0; i < callings.size(); i++ )
    {
        // 호명한 사람의 등수 임시 저장
        int temp = PlayersToRank[callings[i]];
        
        // 이전 등수의 선수 임시 저장
        string TempPlayer = RankToPlayers[temp-1];
        
        // 두 가지 맵 모두 갱신
        RankToPlayers[temp-1] =callings[i];
        RankToPlayers[temp] = TempPlayer;
        
        PlayersToRank[callings[i]] = temp - 1;
        PlayersToRank[TempPlayer] = temp;
        
        
    }
    
    // answer로 등수 대로 추출한다
    for (int i = 1; i < players.size()+1; i++ )
    {
        answer.push_back(RankToPlayers[i]);
    }
    
    
    return answer;
}