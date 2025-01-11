#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(vector<int> ingredient) {
    int answer = 0;
    vector<int> Hamburger;
    
    // 네 개의 요소를 복사할 SubVector
    for (int i = 0; i < ingredient.size(); i++)
    {
    	Hamburger.push_back(ingredient[i]);
        
        // 햄버거가 만들어졌을 경우
        if (Hamburger.size() >= 4 &&
            Hamburger[Hamburger.size()-1] == 1 &&
            Hamburger[Hamburger.size()-2] == 3 &&
            Hamburger[Hamburger.size()-3] == 2 &&
            Hamburger[Hamburger.size()-4] == 1)
        {
            Hamburger.erase(Hamburger.end()-4, Hamburger.end());
            answer++;
        }
    }
    
    return answer;
}
        