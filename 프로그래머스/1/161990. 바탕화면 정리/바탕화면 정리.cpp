#include <string>
#include <vector>
#include <utility>

using namespace std;

vector<int> solution(vector<string> wallpaper) {
    vector<int> answer;
    pair <int, int> MaxIndex = {0, 0};
    pair <int, int> MinIndex = {wallpaper.size(), wallpaper[0].length()};
    
    for (int i = 0; i < wallpaper.size(); i++)
    {
        for (int j = 0; j < wallpaper[i].length(); j++)
        {
            if (wallpaper[i][j] == '#')
            {
                if(MaxIndex.first < i)
                {
                    MaxIndex.first = i;
                }
                if(MaxIndex.second < j)
                {
                    MaxIndex.second = j;
                }
                if(MinIndex.first > i)
                {
                    MinIndex.first = i;
                }
                if(MinIndex.second > j)
                {
                    MinIndex.second = j;
                }
            }
        }
    }
    
    answer.push_back(MinIndex.first);
    answer.push_back(MinIndex.second);
    answer.push_back(MaxIndex.first + 1);  
    answer.push_back(MaxIndex.second + 1);  
    
    return answer;
}