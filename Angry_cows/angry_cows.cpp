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
	setIO("angry");

	int n;
	cin >> n;
	vector<int> line(n);
	for (int i = 0; i < n; i++)
	{
		cin >> line[i];
	}

	sort(line.begin(), line.end());

	int ans = 0;

	for (int i = 0; i < n; i++)
	{
		int t = 1;
		int curr = 1;
		for (int j = i; j < n - 1; j++)
		{
			int k = 1;
			while (j + k < n && line[j + k] - line[j] <= t && k <= t)
			{
				k++;
				curr++;
			}
			t++;
			j += k-2;
			if (k == 1)
			{
				break;
			}
		}

		t = 1;

		for (int j = i; j > 0; j--)
		{
			int k = 1;
			while (j - k >= 0 && line[j] - line[j - k] <= t && k <= t)
			{
				k++;
				curr++;
			}
			t++;
			j -= k-2;
			if (k == 1)
			{
				break;
			}
		}
		ans = max(ans, curr);
	}

	cout << ans << '\n';
}