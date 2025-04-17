#include <string>
#include <vector>
#include <numeric>
#include <queue>

using namespace std;

int solution(vector<int> queue1, vector<int> queue2) 
{
    long long sum1 = accumulate(queue1.begin(), queue1.end(), 0LL);
    long long sum2 = accumulate(queue2.begin(), queue2.end(), 0LL);
    long long total = sum1 + sum2;

    if (total % 2 != 0) return -1;  // 합이 홀수면 불가능!!

    long long target = total / 2;

    queue<int> q1, q2;
    for (int num : queue1) q1.push(num);
    for (int num : queue2) q2.push(num);

    int n = queue1.size();
    int moves = 0;
    int limit = n * 3;  // 충분히 넉넉한 이동 제한

    while (moves <= limit) 
    {
        if (sum1 == target) return moves;

        if (sum1 > target) 
        {
            int x = q1.front(); q1.pop();
            sum1 -= x;
            sum2 += x;
            q2.push(x);
        } 
        else 
        {
            int x = q2.front(); q2.pop();
            sum2 -= x;
            sum1 += x;
            q1.push(x);
        }
        moves++;
    }

    return -1;
}