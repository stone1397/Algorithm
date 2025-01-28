#include <iostream>

using namespace std;

int solution(int n, int a, int b) {
    int answer = 1;

    while ((a - 1) / 2 != (b - 1) / 2) {  // a와 b가 같은 그룹인지 확인
        a = (a + 1) / 2;  // a의 다음 라운드 번호 계산
        b = (b + 1) / 2;  // b의 다음 라운드 번호 계산
        answer++;
    }

    return answer;
}
