#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>
#include <sstream>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> fees, vector<string> records) {
    vector<int> answer;
    unordered_map<int, int> CarNumAndTime;  // 차량 번호 -> 누적 주차 시간
    map<int, int> CarNumAndFee;  // 차량 번호 -> 주차 요금

    // 차량 번호별 주차 시간 계산
    for (string record : records) {
        replace(record.begin(), record.end(), ':', ' ');  // ':'을 공백으로 변경
        
        istringstream ISS(record);
        string HHS, MMS, CarNumS, InAndOut;
        int HH, MM, CarNum, Time;
        
        ISS >> HHS >> MMS >> CarNumS >> InAndOut;
        
        HH = stoi(HHS); 
        MM = stoi(MMS);
        CarNum = stoi(CarNumS);

        Time = HH * 60 + MM;  // 분 단위 변환

        if (InAndOut == "IN") {
            Time = -Time;  // 입차 시 음수 저장
        }

        // 시간 누적
        CarNumAndTime[CarNum] += Time;
    }

    // 23:59까지 출차하지 않은 차량 처리
    for (auto& NumTimePair : CarNumAndTime) {  // 참조로 사용해야 값이 반영됨
        if (NumTimePair.second <= 0) {
            NumTimePair.second += 1439;  // 23:59 (1439분)을 더해줌
        }
    }

    // 요금 계산
    for (auto NumTimePair : CarNumAndTime) {
        int totalTime = NumTimePair.second;
        int fee = fees[1];  // 기본 요금

        if (totalTime > fees[0]) {
            fee += ((totalTime - fees[0] + fees[2] - 1) / fees[2]) * fees[3];  // 올림 계산
        }

        CarNumAndFee[NumTimePair.first] = fee;
    }

    // 정렬된 차량 번호 순서로 요금 추가
    for (auto NumFeePair : CarNumAndFee) {
        answer.push_back(NumFeePair.second);
    }

    return answer;
}