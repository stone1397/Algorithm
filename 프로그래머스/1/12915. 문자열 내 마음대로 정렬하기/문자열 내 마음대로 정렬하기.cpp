#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Compare {
private:
	int n;

public:
	Compare(int index): n(index) {}
    
    // 함수 호출 연산자 () 정의: 객체를 함수처럼 사용할 수 있다.
	bool operator() (string a, string b) { 
		if ( a[n] == b[n] ) {
		return a < b;
        }   
		else {
			return a[n] < b[n];
		}
    }
};

vector<string> solution(vector<string> strings, int n) {
    vector<string> answer;
    answer = strings;

    sort(answer.begin(), answer.end(), Compare(n));
    
    
    return answer;
}