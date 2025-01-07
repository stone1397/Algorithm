#include <string>
#include <vector>

using namespace std;

int solution(vector<string> babbling) 
{
    int answer = 0;
    int max_word_number = 0;
    vector<string> can_speak = {"aya", "ye", "woo", "ma"};
    // babbling 순회하며 같은 단어 찾기
    for (int i = 0; i < babbling.size(); i++)
    {
	    string temp = "";
	    bool is_same = true;
	    while(is_same == true )
	    {
		    for (int j = 0; j < can_speak.size(); j++)
		    {
			    
			    is_same = false;
			    // 인덱스 0~temp.length의 길이만큼 자름
			    if (babbling[i].substr(0, can_speak[j].length()) == can_speak[j] && can_speak[j] != temp)
			    {
					  // temp.legnth부터 끝까지(명시 안해서) 자름
				    babbling[i] = babbling[i].substr(can_speak[j].length());
				    
				    //아직까지는 같다라는 의미
				    is_same = true;
				    
				    // 다음에는 temp를 포함하지 않게 하기 위해
				    temp = can_speak[j];
				    break;
				  }
				}
				// babbling 단어와 전부 일치할 경우
				if(babbling[i] == "")
				{
					answer++;
					break;
				}
			}
		}
    
    return answer;
}