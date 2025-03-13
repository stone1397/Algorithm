#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool compareDigit(const string& a, const string& b) 
{
    return a + b > b + a;
}

string solution(vector<int> numbers) {
    string answer = "";
    vector<string> num_string;
    // 문자열로 변환해서 삽입
    for (int num : numbers)
    {
        num_string.emplace_back(to_string(num));
    }
    // 정렬
    sort(num_string.begin(), num_string.end(), compareDigit);
    
    // 문자열 내의 원소들을 전부 더한다.
    for (string ns : num_string)
    {
        answer+= ns;
    }
    // 000... 일 경우는 0을 출력
    if (answer[0] == '0')
        return "0";
    
    return answer;
}