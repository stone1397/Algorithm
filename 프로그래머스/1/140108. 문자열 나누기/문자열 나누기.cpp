#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    int answer = 0;
    int same_count = 0;
    int diff_count = 0;
    
    int cur_index = 0;
    while(!s.empty())
    {
        for (int i = 0; i < s.length(); i++)
        {
            if(s[i] == s[0])
            {
                same_count++;
            }
            else
            {
                diff_count++;
            }
            if(same_count == diff_count)
            {
                cur_index = i;
                break;
            }
            else if (i == s.length()-1)
            {
                cur_index = s.length() - 1;
            }
        }
        
        s = s.substr(cur_index + 1, s.length()-(cur_index + 1));
        answer++;
    }
          
      
    
    
    
    return answer;
}