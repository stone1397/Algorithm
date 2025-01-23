#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string CountToBinary(int n) {
    string Binary = "";
    while (n > 0) {
        Binary.append(to_string(n % 2)); // 나머지를 추가
        n = n / 2;
    }
    reverse(Binary.begin(), Binary.end()); // 뒤집어서 올바른 순서로 반환
    return Binary;
}


vector<int> solution(string s) {
    vector<int> answer;
   
    int CountZero = 0;
    int ChangeCount = 0;
    int CountOne;
    while (s != "1")
    {
        CountOne = 0;
        for (char c : s)
        {
            if (c == '0')
            {
                CountZero++;
            }
            if (c == '1')
            {
                CountOne++;
            }
        }
        // 이진 변환 후 카운트 증가
        s = CountToBinary(CountOne);
        ChangeCount++;
        // s 가 1이 될 때까지
        if (s == "1")
        {
            break;
        }
    }
    answer.push_back(ChangeCount);
    answer.push_back(CountZero);
    return answer;
}