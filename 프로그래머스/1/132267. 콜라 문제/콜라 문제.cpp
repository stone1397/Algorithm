#include <string>
#include <vector>

using namespace std;

int solution (int a, int b, int n) {
	int answer = 0;
	int empty_cola = n;
	while (empty_cola >= a) {
		empty_cola = empty_cola - (a - b);
		answer = answer + b;
	}
	return answer;
}