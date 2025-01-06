#include <string>
#include <vector>

using namespace std;

int solution(int number, int limit, int power) 
{
    int answer = 0;
   
    for (int i = 1 ; i < number + 1; i++)
    {
        int div_num = 0;  // 오류 수정 -> 초기화하는 코드 추가
	    for (int j = 1; j*j <= i ; j++)
	    {
		    if( i % j == 0)
            {
                div_num++;
			    if ( j != i / j) // 제곱수가 아니라면
				    div_num++;
            }
		}
		if (div_num > limit)
			answer = answer + power;
		else
			answer = answer  + div_num;
    } 
    
    
    return answer;
}