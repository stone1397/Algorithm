#include <string>
#include <vector>

using namespace std;

vector<int> solution (vector<int> answers) {
	vector<int> answer;
	
	// 규칙을 담은 배열
	vector<int> counts = { 0, 0, 0 };
	vector<int> two = { 1, 3, 4, 5 };
	vector<int> three = { 3, 1, 2, 4, 5 };
	
	// 점수 주기
	for (int i = 0 ; i < answers.size(); i++) {
		int math_one = (i%5) + 1;
		int math_two = (i%2 == 0)? 2 : two[(i % 8)/2];
		int math_three = three[(i % 10) / 2];
		
		
		if ( answers[i] == (math_one))
			counts[0]++;
		if ( answers[i] == (math_two))
			counts[1]++;
		if ( answers[i] == (math_three))
			counts[2]++;
	}
	int max_count = counts[0];
	
	// 최다 득점자 찾기
	for (int i = 1; i < 3 ; i++) {
		if(max_count < counts[i])
			max_count = counts[i];
	}
	
	// answer 배열에 넣기
	for (int i = 0; i < 3; i++) {
		if(counts[i] == max_count) 
			answer.push_back(i+1);
	}
	
	return answer;
}