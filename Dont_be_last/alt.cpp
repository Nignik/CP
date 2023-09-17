#include <bits/stdc++.h>

using namespace std;

constexpr int COW_NUM = 7;

int main() {
	int n;
	cin >> n;

	map<string, set<string>> m;
	int cnt = 0;

	map<string, map<string, int>> a;

	for (int i = 0; i < n; i++)
	{
		string s1, s2;
		cin >> s1 >> s2;

		if (m[s2].find(s1.substr(0, 2)) != m[s2].end())
		{
			if (a.count(s2) != 0)
			{
				a[s2][s1.substr(0, 2)]++;
			}
			else
			{
				a[s2][s1.substr(0, 2)] = 0;
			}
		}
		else
		{
			m[s2].insert(s1.substr(0, 2));
		}
	}

	for (const auto& i : m)
	{
		for (const auto& j : i.second)
		{
			cnt += min(a[j][i.first], a[i.first][j]);
		}
	}

	cout << cnt << '\n';
}