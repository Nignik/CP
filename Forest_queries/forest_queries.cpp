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
	setIO("blist");

	int n, q;
	cin >> n >> q;
	vector<vector<int>> f(n+1, vector<int>(n+1));
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			char c;
			cin >> c;
			if (c == '*') f[i][j] = 1;
			else f[i][j] = 0;
		}
	}

	vector<vector<int>> p(n+1, vector<int>(n+1));
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			p[i][j] = p[i-1][j] + p[i][j-1] - p[i-1][j-1] + f[i][j];
		}
	}

	for (int i = 0; i < q; i++) {
		int y1, x1, y2, x2;
		cin >> y1 >> x1 >> y2 >> x2;

		cout << p[y2][x2] - p[y2][x1-1] - p[y1-1][x2] + p[y1-1][x1-1] << '\n';
	}
}