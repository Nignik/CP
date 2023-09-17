#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void setIO(string s) {
	ios_base::sync_with_stdio(0); cin.tie(0);
	if (fopen((s+".in").c_str(), "r")){
		freopen((s+".in").c_str(),"r",stdin);
		freopen((s+".out").c_str(),"w",stdout);
	}
}

int main() {
	setIO("lazy");

	int n, k;
	cin >> n >> k;
	int old_n = n;
	n = n * 2 - 1;

	vector<vector<int>> a(n + 1, vector<int>(n + 1));
	for (int i = 1; i <= old_n; i++) {
		for (int j = 1; j <= old_n; j++) {
			cin >> a[i + j - 1][old_n - i + j];
		}
	}


	vector<vector<int>> p(n + 1, vector<int>(n + 1));
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			p[i][j] = p[i - 1][j] + p[i][j - 1] - p[i - 1][j - 1] + a[i][j];
		}
	}

	int best = 0;
	for (int i = k + 1; i <= n - k; i++) {
		for (int j = k + 1; j <= n - k; j++) {
			int cnt = p[i + k][j + k] - p[i + k][j - k - 1] - p[i - k - 1][j + k] + p[i - k - 1][j - k - 1];

			best = max(best, cnt);
		}
	}

	cout << best << '\n';
}