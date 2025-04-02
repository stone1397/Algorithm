#include <string>
#include <vector>
#include <queue>

using namespace std;

bool isConvertible(const string& a, const string& b) 
{
    int diff = 0;
    for (int i = 0; i < a.size(); ++i) 
    {
        if (a[i] != b[i]) ++diff;
        if (diff > 1) return false;
    }
    return diff == 1;
}

int solution(string begin, string target, vector<string> words) 
{
    vector<bool> visited(words.size(), false);
    queue<pair<string, int>> wordQueue;

    wordQueue.push({begin, 0});

    while (!wordQueue.empty()) 
    {
        string current = wordQueue.front().first;
        int depth = wordQueue.front().second;
        wordQueue.pop();

        if (current == target) return depth;

        for (int i = 0; i < words.size(); ++i) 
        {
            if (!visited[i] && isConvertible(current, words[i])) 
            {
                visited[i] = true;
                wordQueue.push({words[i], depth + 1});
            }
        }
    }

    return 0;
}