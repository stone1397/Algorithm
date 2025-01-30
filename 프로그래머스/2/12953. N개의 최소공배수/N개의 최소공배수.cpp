#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int Find_Lcm (int InA, int InB)
{
    int Lcm = 0;
    int LargeNum = max(InA, InB);
    int SmallNum = min(InA, InB);
    int Remain = 1;
    while(Remain != 0)
    {
        Remain = LargeNum % SmallNum;
        LargeNum = SmallNum;
        SmallNum = Remain;
    }
    Lcm = InA * InB / LargeNum; // lcm = a * b / gcd
    return Lcm;
}

int solution(vector<int> arr) {
    int answer = 0;
    int Lcm = Find_Lcm(arr[0], arr[1]);
    for (int i = 2; i < arr.size(); i++)
    {
        Lcm = Find_Lcm(Lcm, arr[i]);
    }
    answer = Lcm;
    return answer;
}