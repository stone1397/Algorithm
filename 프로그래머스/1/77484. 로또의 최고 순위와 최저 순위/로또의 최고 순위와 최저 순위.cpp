#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> lottos, vector<int> win_nums) 
{
		int count = -1;
		int zero_count = 0;
		int first = 6;
    vector<int> answer;
    for (int i = 0; i < lottos.size(); i++)
    {
	    for (int j = 0; j < win_nums.size(); j++)
	    {
		    if(lottos[i] == 0)
		    {
			    zero_count++;
			    break;
			}
			else if (win_nums[j] == lottos[i])
			{
				  count++;
				  break;
		    }
		}
	}
    int max_rank = min(6, first- (count + zero_count));
    int min_rank = min(6, first - (count));
	answer.push_back(max_rank);
	answer.push_back(min_rank);
		    
    return answer;
}