#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    int width = 0;
    int height = 0;
    for (int i = 3; i < brown ; i++)
    {
        for (int j = 3; j < brown ; j++)
        {
            if (i >= j &&(i + j)* 2 - 4 == brown && (i-2)*(j-2) == yellow)
            {
                height = j;
                break; 
            }
        }
        if (height != 0)
        {
            width = i;
            break;
        }        
    }
    answer.emplace_back(width);
    answer.emplace_back(height);
    
    return answer;
}
    