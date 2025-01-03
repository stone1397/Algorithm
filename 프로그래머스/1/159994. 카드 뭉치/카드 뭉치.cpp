#include <string>
#include <vector>

using namespace std;

string answer = "";

string solution(vector<string> cards1, vector<string> cards2, vector<string> goal) {
	answer = "Yes";
    int count1 = 0;
	int count2 = 0;
	for (int i = 0 ; i < goal.size(); i++) {

		if( goal[i] == cards1[count1])
			count1++;
		else if (goal[i] == cards2[count2])
			count2++;
		else {
			answer = "No";
			break;
		}
    }
    return answer;
}