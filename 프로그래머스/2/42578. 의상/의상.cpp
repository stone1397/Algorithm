#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

int solution(vector<vector<string>> clothes) {
    // 의상의 종류별 개수 저장
    std::unordered_map<std::string, int> ClothesKindNums;

    for (const auto &item : clothes) {
        ClothesKindNums[item[1]]++; // 의상 종류별 개수 증가
    }

    // 모든 경우의 수 계산
    int answer = 1; // 곱셈을 위해 초기값 1
    for (const auto &pair : ClothesKindNums) {
        answer *= (pair.second + 1); // 각 종류의 의상을 입지 않는 경우 포함
    }

    // 공집합(아무 것도 입지 않는 경우)을 제외
    return answer - 1;
}