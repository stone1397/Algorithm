#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr) {
    vector<int> answer;
    int minIndex = 0;
    int minValue = arr[0];
    
    for (int i =1; i < arr.size(); i++) {
        if(arr[i] < minValue) {
            minValue = arr[i];
            minIndex = i;
        }
    }
    
    arr.erase(arr.begin() + minIndex);
    answer = arr;
    if (answer.begin() == answer.end()){
        return {-1};
    }
    else {
        return answer;
    }
    
}