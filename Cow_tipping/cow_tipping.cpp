#include <bits/stdc++.h>

using namespace std;

void setIO(string s) {
	ios_base::sync_with_stdio(0); cin.tie(0);
	if (fopen((s+".in").c_str(), "r")){
		freopen((s+".in").c_str(),"r",stdin);
		freopen((s+".out").c_str(),"w",stdout);
	}
}

const char TIPPED = '0';

bool flip(int r, int c, vector<vector<bool>> &cows) {
	if (cows[r][c]) {
		for (int ri = 0; ri <= r; ri++) {
			for (int ci = 0; ci <= c; ci++) {
				cows[ri][ci] =! cows[ri][ci];
			}
		}
		return true;
	}
	return false;
}

int main() {
	setIO("cowtip");

	int n;
	cin >> n;
	vector<vector<bool>> a(n, vector<bool>(n));
	for (int r = 0; r < n; r++) {
		string row;
		cin >> row;
		for (int c = 0; c < n; c++) { a[r][c] = row[c] != TIPPED; }
	}

	int x = n-1;
	int y = n-1;
	int cnt = 0;
	while (x >= 0 && y >= 0) {
		cnt += flip(x, y, a);
		if (x != y) {
			cnt += flip(y, x, a);
		}

		if (x > 0) {
			x--;
		}
		else {
			y--;
			x = y;
		}
	}

	cout << cnt << '\n';
}