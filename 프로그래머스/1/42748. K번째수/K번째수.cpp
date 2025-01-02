#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    
    // 반복문 순회 -> 벡터 자르고 저장
    for (int i = 0; i < commands.size(); i++) {
        vector<int> current_slice = vector(array.begin() + commands[i][0] - 1, array.begin() + commands[i][1]);
        
        // 정렬
        sort(current_slice.begin(), current_slice.end());
        
        // k번째 원소 저장
        answer.push_back(current_slice[commands[i][2]-1]);
    }
    
    return answer;
}