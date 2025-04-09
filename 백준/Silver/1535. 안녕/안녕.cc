#include<iostream>
#include<vector>

using namespace std;

int maxJoy = 0;

void dfs(const vector<int>& l, const vector<int>&  j, int index, int health, int joy)
{
	// 종료 조건
	if (health <= 0) return;

	maxJoy = max(maxJoy, joy);

	for (int i = index; i < l.size(); i++)
	{
		dfs(l, j, i + 1, health - l[i], joy + j[i]);
	}

}


int main()
{
	int initialHealth = 100;
	int initialJoy = 0;
	int initialIndex = 0;
	int n;
	cin >> n;

	vector<int> l;
	l.resize(n);
	vector<int> j;
	j.resize(n);
	for (int i = 0; i < n; i++) cin >> l[i];

	for (int i = 0; i < n; i++) cin >> j[i];

	dfs(l, j, initialIndex, initialHealth, initialJoy);

	cout << maxJoy << endl;

	return 0;
}