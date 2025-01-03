#include <string>
#include <vector>

using namespace std;

string solution (int a, int b) {
	vector<int> month = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	vector<string> day_of_week = {"FRI","SAT","SUN","MON","TUE","WED","THU"};
	int day = b-1;
	for (int i = 0 ; i < a-1; i++) {
		day += month[i];
	}
	
	string answer = day_of_week[day%7];

    return answer;
}