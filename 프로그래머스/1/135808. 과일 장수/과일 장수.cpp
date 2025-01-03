#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(int a, int b) {
		return a > b;
}

int solution(int k, int m, vector<int> score) {
    int answer = 0;
    int p = k;
    sort(score.begin(), score.end(), compare);
    for (int i = 1; i < score.size(); i++ ) {
		  if (score[i] < score[i-1] && score[i] < k) {
			  p = score[i];
			}
			
		  if ((i+1) % m == 0 && (i+1) >= m) {
			  answer += m * p;
			}
		}
    return answer;
}