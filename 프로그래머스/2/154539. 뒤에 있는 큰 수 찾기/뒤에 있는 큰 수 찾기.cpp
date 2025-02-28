#include <string>
#include <vector>
#include <stack>

using namespace std;


vector<int> solution(vector<int> numbers) {
    
    stack<int> numbersStack;
    int numSize = numbers.size();
    vector<int> answer(numSize, -1);
    for (int i = numSize - 1; i >= 0; i--)
    {
        while(!numbersStack.empty() && numbersStack.top() <= numbers[i])
        {
            numbersStack.pop();
        }
        
        if (!numbersStack.empty())
        {
            answer[i] = numbersStack.top();
        }
        numbersStack.push(numbers[i]);
    }
    return answer;
}