#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(char a, char b) {
	return a > b;
}

string solution (vector<int> food) {
	string answer = "";
	for ( int i = 0 ; i < food.size(); i++ ) {
		for (int j = 0; j < food[i]/2; j++) {
			answer.push_back(i + '0');
		}
	}
	string answer_reverse = answer;
	sort(answer_reverse.begin(), answer_reverse.end(), compare);
	answer = answer + "0" + answer_reverse;
    
    return answer;
}