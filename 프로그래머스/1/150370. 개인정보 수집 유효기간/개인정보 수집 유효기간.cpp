#include <string>
#include <vector>
#include <unordered_map>
#include <sstream>
#include <iostream>

using namespace std;

// 문자열 -> 날짜 변환
void parseDate(const std::string& dateStr, int& year, int& month, int& day)
{
	char delim;
	std::istringstream ss(dateStr);
	ss >> year >> delim >> month >> delim >> day;
}
// '달'을 기준으로 날짜 더하기
void addMonths(int& year, int& month, int monthsToAdd)
{
	month += monthsToAdd;
	while (month > 12)
	{
		month -= 12;
		year++;
	}
}

// 날짜를 비교
bool IsExpired(int y1, int m1, int d1, int y2, int m2, int d2) {
    if (y1 < y2) return true;
    if (y1 == y2 && m1 < m2) return true;
    if (y1 == y2 && m1 == m2 && d1 <= d2) return true;
    return false;
}

 
vector<int> solution(string today, vector<string> terms, vector<string> privacies) {
    vector<int> answer;
    unordered_map<string, int> TermPair;
    
    // 오늘 날짜를 변환
    int TodayYear, TodayMonth, TodayDay;
    parseDate(today, TodayYear, TodayMonth, TodayDay);
    
    // 맵에 terms의 원소 str을 (종류, 달 수)로 저장
    for (string str : terms)
    {
        std::istringstream ss(str);
        std::string type;
        int months;
        ss >> type >> months;
        TermPair[type] = months;
    }
    
    // 유효성을 검사
    for (int i = 0; i < privacies.size(); i++)
    {
        // privacies 문자열 분리
        std::istringstream ss(privacies[i]);
        std::string date, type;
        ss >> date >> type;
        
        int year, month, day;
        parseDate(date, year, month, day);
        
        // 달 수 추가
        addMonths(year, month, TermPair[type]);
        
        // 유효 기간 확인
        if (IsExpired(year, month, day, TodayYear, TodayMonth, TodayDay))
        {
            answer.push_back(i + 1);
        }
    }
    
    
    
    return answer;
}