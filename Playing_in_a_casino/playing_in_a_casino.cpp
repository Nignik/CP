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

	int t;
	cin >> t;
	while (t--) {
		int n, m;
		long long ans = 0;
		cin >> n >> m;
		vector<vector<int>> a(m, vector<int>(n)); 
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cin >> a[j][i];
			}
		}

		for (int i = 0; i < m; i++) {
			long long sum = 0;

			for (int j = 0; j < n; j++) {
				sum += a[i][j];
			}
			sort(a[i].begin(), a[i].end());

			long long curr = 0;
			for (int j = 0; j < n; j++) {
				curr += a[i][j];
				ans += llabs((sum - curr) - (n - 1 - j) * (long long)a[i][j]);
			}
		}
		cout << ans << '\n';

	}
}