#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

string solution(vector<string> survey, vector<int> choices) {
    string answer = "";
    
    // 분야별 점수 저장
    unordered_map<string,int> score = {
        {"RT", 0},
        {"TR", 0},
        {"FC", 0},
        {"CF", 0},
        {"MJ", 0},
        {"JM", 0},
        {"AN", 0},
        {"NA", 0},
    };
    
    // 점수 계산
    for(int i = 0; i < survey.size(); i++)
    {
        score[survey[i]] = score[survey[i]] + (4 - choices[i]);
    }
    
    // 점수 비교
    if (score["RT"] >= score["TR"])
    {
        answer.push_back('R');
    }
    else 
    {
        answer.push_back('T');
    }
    if (score["CF"] >= score["FC"])
    {
        answer.push_back('C');
    }
    else 
    {
        answer.push_back('F');
    }
    if (score["JM"] >= score["MJ"])
    {
        answer.push_back('J');
    }
    else 
    {
        answer.push_back('M');
    }
    if (score["AN"] >= score["NA"])
    {
        answer.push_back('A');
    }
    else 
    {
        answer.push_back('N');
    }
    
    return answer;
}