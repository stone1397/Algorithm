#include <string>
#include <vector>


using namespace std;
/*
//조합 함수
long long Combination(int n, int r)
{
    if (r == 0 || r == n) return 1; // 0C0 = 1, nCn = 1
    if (r > n) return 0; // 정의되지 않은 경우 방지
    
    if (r > (n - r))
    {
        r = n - r;
    }
    long long result = 1;
    for (int i = 0; i < r; i++)
    {
        result *= (n-i);
        result /= (i+1);
    }
    return result;
}


long long solution(int n) {
    long long answer = 0;
    int a = n;
    int b = n;
    while(b >= 0)
    {
        answer = (answer + Combination(a, b)) % 1234567;
//        cout << Combination(a, b) << endl;
        a -=1;
        b -=2;
    }
//    answer = answer % 1234567;
    return answer;
}
*/

long long solution(int n)
{
    
    long long answer = 0;
    vector<long long> Fibonacci;
    Fibonacci.reserve(n+1);
    Fibonacci[1] = 1;
    if (n >= 2)
    {
        Fibonacci[2] = 2;
        for (int i = 3; i <= n ; i++)
        {
            Fibonacci[i] = (Fibonacci[i-1] + Fibonacci[i-2]) % 1234567;
        }
    }
    answer = Fibonacci[n];
    return answer;
    
}