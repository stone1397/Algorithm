#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iostream>

using namespace std;


bool IsPrime(long long N) 
{
    if (N < 2) return false;
    if (N == 2 || N == 3) return true;
    if (N % 2 == 0 || N % 3 == 0) return false; // 2와 3의 배수 제거
    
    for (long long i = 5; i * i <= N; i += 6) {
        if (N % i == 0 || N % (i + 2) == 0) return false; // 6의 배수 활용
    }
    return true;
}

int solution(int N, int K) 
{
    int Answer = 0;
    
    // N을 K진수로 바꾸기
    vector<int> KNum;
    vector<long long> DNum;
    while (N > 0)
    {
        KNum.push_back(N % K);
        N /= K;
    }
    reverse(KNum.begin(), KNum.end()); // KNum을 정방향으로 정렬

    // K진수를 0을 기준으로 십진수로 저장 (변환하는 것이 아니라 그대로 저장)
    long long DecimalNum = 0;
    for (int Digit : KNum) 
    {
        if (Digit == 0) 
        {
            if (DecimalNum > 0) 
            {
                DNum.push_back(DecimalNum);
                DecimalNum = 0;
            }
        } 
        else 
        {
            DecimalNum = DecimalNum * 10 + Digit; // K진수를 10진수로 저장
        }
    }
    // 마지막 숫자가 남아 있으면 추가해야 함
    if (DecimalNum > 0) 
    {
        DNum.push_back(DecimalNum);
    }
    // DNum에 넣은 수들이 소수인지 확인
//    cout << DNum.size() << endl;
    for (long long Num : DNum)
    {
        if (IsPrime(Num)) 
        {
            Answer++;
//            cout << Num << endl;
        }
        else
        {
//          cout << "NotPrime: " << Num << endl;
        }
    }
    return Answer;
}