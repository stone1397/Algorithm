#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    
    size_t pos = s.find(' '); // 첫 번째 공백 찾기
    int first = stoi(s.substr(0, pos)); // 첫 번째 값 추출
    string rest = s.substr(pos+1); // 나머지 문자열 추출
    int maxValue = first;
    int minValue = first; // 초기 최대, 최소값 지정
    
    while (true)
    {
        pos = rest.find(' '); // 반복문 돌며 첫 번째 공백 찾기
        if (pos == string::npos) // 마지막 숫자일 경우
        { 
            first = stoi(rest);   // 남은 문자열 전체를 숫자로 변환
            minValue = min(minValue, first);
            maxValue = max(maxValue, first);
            break;                // 마지막 숫자 처리 후 반복문 종료
        }
        
        
        first = stoi(rest.substr(0, pos)); // 첫 번째 값 추출
        rest = rest.substr(pos + 1); // 나머지 문자열을 다시 rest에 대입
        
        minValue = min(minValue, first);
        maxValue = max(maxValue, first);
        

    }
    // 정수형 문자열로 전환 후 문자열에 삽입
    string answer = to_string(minValue) + " " + to_string(maxValue);
    
    return answer;
}