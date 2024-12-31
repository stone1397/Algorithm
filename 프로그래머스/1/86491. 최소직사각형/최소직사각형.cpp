#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> sizes) {
    int answer = 0;
    int first_max = sizes[0][0];
    int max_index[2] = {0, 0};
    
    for (int i = 0; i < sizes.size(); i++) {
        for (int j = 0; j < 2; j++) {
            if(sizes[i][j] > first_max) {
                first_max = sizes[i][j];
                max_index[0] = i;
                max_index[1] = j;
            }
        }
    }
    // max_index[1]의 반대 값으로 작은 값들을 몬다.
    int other_side = (max_index[1] == 0) ? 1 : 0;
    int second_max = 0;
    
    for (int i = 0; i < sizes.size(); i++ ) {
        if(sizes[i][max_index[1]] < sizes[i][other_side]) {
            swap(sizes[i][max_index[1]], sizes[i][other_side]);    
        }
        
        if(sizes[i][other_side] > second_max) {
            second_max = sizes[i][other_side];
        }
        
    }
    answer = first_max * second_max;
    
    return answer;
}