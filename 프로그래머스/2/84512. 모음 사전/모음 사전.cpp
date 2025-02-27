#include <string>
#include <vector>
#include <unordered_map>
#include <cmath>

using namespace std;

int solution(string word) {
    int answer = 0;
    int sum = 0;
    vector<int> weights;
    unordered_map<char, int> alphaWeights;
    alphaWeights.emplace('A', 0);
    alphaWeights.emplace('E', 1);
    alphaWeights.emplace('I', 2);
    alphaWeights.emplace('O', 3);
    alphaWeights.emplace('U', 4);
    
    weights.reserve(5);
    // 가중치 구해주기
    for (int i = 0; i < 5 ; i++)
    {
        sum += pow(5, i);
        weights.push_back(sum);
    }
    // 순서 구하기
    for (int i = 0; i < word.size(); i++)
    {

        answer += alphaWeights[word[i]] * weights[4-i] + 1;   
    }
    return answer;
}