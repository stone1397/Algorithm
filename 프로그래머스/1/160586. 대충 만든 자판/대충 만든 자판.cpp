#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>


using namespace std;

vector<int> solution(vector<string> keymap, vector<string> targets) 
{
   
    // 문자와 숫자를 저장할 map을 만든다.
    unordered_map<char, int> min_press_count;
    
    // map 생성
    for(const string& keys : keymap)
    {
	    for(int i = 0; i < keys.size(); i++)
	    {
		    char c = keys[i];
		    // 해당 문자가 처음 등장한 경우
		    if(min_press_count.find(c) == min_press_count.end())
		    {
			    min_press_count[c] = i + 1;
			}
			  // 처음 등장한 것이 아닌 경우
			  else
			  {
				  min_press_count[c] = min(min_press_count[c], i + 1);
			  }
		}
	}
		
	vector<int> answer;
	
	//targets의 원소와 자판 개수 연결하기
	for(const string& target : targets)
	{
		int sum_count = 0; // 해당 target의 총 입력 횟수
		bool found_all = true; // 모든 문자를 찾았는지 
		
		for (char c : target)
		{
			// 해당 문자를 찾을 수 없는 경우
			if(min_press_count.find(c) == min_press_count.end())
			{
				found_all = false;
				break;
			}
			else
			{
				// 찾았을 경우 count를 늘린다.
				sum_count += min_press_count[c];
			}
		}
			
		if(!found_all)
		{
			answer.push_back(-1);
		}
		else
		{
			answer.push_back(sum_count);
		}
	}
		
    
    
  return answer;
 }