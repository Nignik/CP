#include <bits/stdc++.h>

using namespace std;

void setIO(string s) {
	ios_base::sync_with_stdio(0); cin.tie(0);
	if (fopen((s+".in").c_str(), "r")){
		freopen((s+".in").c_str(),"r",stdin);
		freopen((s+".out").c_str(),"w",stdout);
	}
}

int main() {
	setIO("blist");

	int n, k;
	cin >> n >> k;
	vector<int> m(n);
	vector<int> p(k);
	set<int> check;
	cin >> m[0];
	for (int i = 1; i < n; i++)
	{
		int z;
		cin >> z;
		m[i] = m[i - 1] + z;
	}
	for (int i = 0; i < k; i++)
	{
		cin >> p[i];
		check.insert(p[i]);
	}

	set<int> ans;
	unordered_map<int, unordered_set<int>> start;

	for (int t = n - 1; t >= 0; t--)
	{
		for (int i = 0; i < k; i++)
		{
			start[p[i]-m[t]].insert(p[i]);
		}
	}

	if (k > 1000) {
		cout << start.size() << '\n';
		return 0;
	}

	for (const auto& i : start)
	{
		/*bool valid = true;
		for (const auto& j : check)
		{
			if (i.second.find(j) == i.second.end())
			{
				valid = false;
				break;
			}
		}
		if (valid)
		{
			ans.insert(i.first);
		}*/

		if (i.second.size() == check.size()) {
			ans.insert(i.first);
		}
	}

	cout << ans.size() << '\n';
}