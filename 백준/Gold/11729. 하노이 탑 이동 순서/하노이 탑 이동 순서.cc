#include <iostream>
#include <vector>
using namespace std;

void hanoi(int n, int start, int target, int sub, vector<pair<int, int>>& moves) {
    if (n == 1) 
    {
        moves.push_back({ start, target });
    }
    else 
    {
        hanoi(n - 1, start, sub, target, moves); // n-1개의 원판을 모두 sub에 쌓는다.
        moves.push_back({ start, target }); // 가장 무거운 n번째 원판을 target에 쌓는다.
        hanoi(n - 1, sub, target, start, moves); // 다시 n-1개의 원판을 target에 쌓는다.
    }
}

int main()
{
    int n;
    cin >> n;
    vector<pair<int, int>> moves;
    hanoi(n, 1, 3, 2, moves);

    cout << moves.size() << "\n";
    for (auto& move : moves) {
        cout << move.first << " " << move.second << "\n";
    }

    return 0;
}