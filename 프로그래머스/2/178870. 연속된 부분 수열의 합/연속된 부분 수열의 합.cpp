#include <string>
#include <vector>
#include <climits>

using namespace std;

vector<int> solution(vector<int> sequence, int k) {
    int n = sequence.size();
    int left = 0, total = 0;
    int min_len = INT_MAX;
    int ans_start = 0, ans_end = 0;

    for (int right = 0; right < n; right++) 
    {
        total += sequence[right];

        while (total > k && left <= right) 
        {
            total -= sequence[left];
            ++left;
        }

        if (total == k) 
        {
            if (right - left < min_len) 
            {
                min_len = right - left;
                ans_start = left;
                ans_end = right;
            }
        }
    }

    return {ans_start, ans_end};
}