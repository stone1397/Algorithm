#include <vector>
#include <iostream>
using namespace std;

int solution(vector<int> nums) {
    int answer = 0;
		
		for (int i = 0; i < nums.size()-2; i++) {
			for (int j = i+1; j < nums.size()-1; j++) {
				for (int k = j+1; k < nums.size(); k++) {
					int sum = nums[i]+nums[j]+nums[k];
					bool isprime_number = true;
					for (int n = 2; n < sum; n++) {
						if(sum % n == 0) {
							isprime_number = false;
						}
					}
				if (isprime_number == true)
					answer++;
                 // [실행] 버튼을 누르면 출력 값을 볼 수 있습니다.
                cout << "answer" << endl;
				}
			}
		}
		
   

    return answer;
}