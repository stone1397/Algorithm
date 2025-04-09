#include<iostream>
#include<string>
#include<vector>

using namespace std;
int main()
{
	string s;
	cin >> s;

	vector<int> counts(26);

	for (char c : s)
	{
		counts[c - 'a']++;
	}

	for (int i = 0; i < 26; i++)
	{
		cout << counts[i];
		if (i < 25) cout << ' ';
	}
	return 0;
}