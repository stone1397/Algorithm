#include <string>
#include <vector>
#include <bitset>

using namespace std;

vector<long long> solution(vector<long long> numbers) {
    vector<long long> answer;
    for (long long num : numbers)
    {
        long long fNum = 0;
        // num을 bit로 변환
        bitset<64> bits(num);
        // 최초로 0이 나오는 위치
        int pos = -1;
        // 순회하면서 0인 비트를 찾기
        for (int i = 0; i < 64; i++)
        {
            if (!bits.test(i))
            {
                pos = i;
                break;
            }
        }
        
        // i를 찾았다면
        if (pos != -1)
        {
            bits.set(pos, 1);
            if (pos != 0)
            {
                bits.set(pos-1, 0);
            }
        }
        fNum = static_cast<long long>(bits.to_ullong());
        answer.push_back(fNum);
    }
    return answer;
}