#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <unordered_map>
#include <unordered_set>
#include <set>

using namespace std;

struct ReportData {
    unordered_map<string, int> ReportedToNum;          // 신고당한 사람 -> 신고 횟수
    unordered_map<string, unordered_set<string>> ReportToReported; // 신고한 사람 -> 신고당한 사람 목록
    vector<int> answer;                                // 결과 저장 벡터
};

// 중복 제거 및 신고 횟수 집계
void StoreReports(const vector<string>& report, ReportData& data) {
    for (const string& ReportLog : report) {
        string Report, Reported;
        istringstream ss(ReportLog);
        ss >> Report >> Reported;

        // 중복 신고 방지: 동일한 신고자가 동일 유저를 신고한 경우 1회만 카운트
        if (data.ReportToReported[Report].insert(Reported).second) {
            data.ReportedToNum[Reported]++;  // 신고 횟수 증가
        }
    }
}

// 신고당한 사람의 배열 순서 저장하기
void MapReportedToSequence(const vector<string>& id_list, ReportData& data) {
    data.answer.resize(id_list.size(), 0);  // answer 초기화
}

// 정지된 유저 처리 및 고지
void ProcessSuspendedUsers(const vector<string>& id_list, int k, ReportData& data) {
    unordered_map<string, int> idToIndex;
    for (int i = 0; i < id_list.size(); i++) {
        idToIndex[id_list[i]] = i;  // 유저 ID -> 인덱스 매핑
    }

    for (const auto& pair : data.ReportedToNum) {
        const string& reported = pair.first;
        int reportCount = pair.second;

        // 신고 횟수가 k 이상인 경우
        if (reportCount >= k) {
            for (const auto& reporter : data.ReportToReported) {
                if (reporter.second.find(reported) != reporter.second.end()) {
                    data.answer[idToIndex[reporter.first]]++;
                }
            }
        }
    }
}

// 메인 함수
vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    ReportData data;

    StoreReports(report, data);
    MapReportedToSequence(id_list, data);
    ProcessSuspendedUsers(id_list, k, data);

    return data.answer;
}
