#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(int a, int b) {
	return a > b;
}


vector<int> solution(int k, vector<int> score) {
	vector<int> answer;
	vector<int> temp;
	for (int i = 0; i < score.size(); i++) {
		temp.push_back(score[i]);
		sort(temp.begin(), temp.end(), compare);
		
	    if (i < k) {
	    	answer.push_back(temp[temp.size()-1]);
	    }
	    else{
	    	answer.push_back(temp[k-1]);
	    }
    } 
	return answer;
}	
		
