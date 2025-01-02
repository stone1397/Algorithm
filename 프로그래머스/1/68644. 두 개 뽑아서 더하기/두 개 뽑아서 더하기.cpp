#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> numbers) {
    vector<int> answer;
    int sum = numbers[0] + numbers[1];
	answer.push_back(sum);
	bool duplicate = false;
	
	for (int i = 0; i < numbers.size()- 1; i++ ) {
		for (int j = i+1; j < numbers.size(); j++ ) {
			 sum = numbers[i] + numbers[j];
			 
			 for ( int num : answer) {
				 if( num == sum ) {
					 duplicate = true;
				 }
			}
			if (!duplicate) {
				answer.push_back(sum);
			}
            else {
                duplicate = false;
            }
            
	    }
    } 
    sort(answer.begin(), answer.end());
    
    return answer;
}