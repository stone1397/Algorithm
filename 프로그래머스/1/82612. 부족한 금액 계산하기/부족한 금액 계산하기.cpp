#include <algorithm>

using namespace std;

long long solution(int price, int money, int count)
{
    long long answer = -1;
    long long fullprice = 0;
    
    for (int i =1; i <= count; i++) {
        fullprice += i* price;
    }
    long long diff = fullprice - money;
    answer = max(0LL, diff);
    return answer;
}