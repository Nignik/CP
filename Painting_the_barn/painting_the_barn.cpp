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
	setIO("paintbarn");

	int n, k;
	cin >> n >> k;
	int max_x = 0;
	int max_y = 0;
	vector<vector<int>> p(1005, vector<int>(1005));
	for (int i = 0; i < n; i++) {
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		max_x = max(max_x, a);
		max_x = max(max_x, c);
		max_y = max(max_y, b);
		max_y = max(max_y, d);
		for (int j = b; j <= d; j++) {
			p[a][j] += 1;
			p[c+1][j] += -1;
		}
	}

	int c = 0;
	int ans = 0;
	for (int i = 0; i < max_y; i++) {
		for (int j = 0; j <= max_x; j++) {
			c += p[i][j];
			if (c == k) {
				ans++;
			}
		}
	}

	cout << ans << '\n';
}