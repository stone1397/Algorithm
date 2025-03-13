#include <string>
#include <vector>
#include <unordered_map>
#include <cmath>

using namespace std;

int solution(string word) {
    int answer = 0;
    vector<int> weights = {781, 156, 31, 6, 1}; // 미리 계산한 가중치
    unordered_map<char, int> alphaWeights = {
        {'A', 0}, {'E', 1}, {'I', 2}, {'O', 3}, {'U', 4}
    };
    
		weights.reserve(5);
    // 단어의 각 글자를 돌면서 순서 계산
    for (int i = 0; i < word.size(); i++) {
        answer += alphaWeights[word[i]] * weights[i] + 1; // +1은 해당 글자 자신을 포함
    }

    return answer;
}

