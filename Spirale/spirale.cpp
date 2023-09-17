#include <bits/stdc++.h>

using namespace std;

void setIO(string s) {
	ios_base::sync_with_stdio(0); cin.tie(0);
	if (fopen((s+".in").c_str(), "r")){
		freopen((s+".in").c_str(),"r",stdin);
		freopen((s+".out").c_str(),"w",stdout);
	}
}

int mat[50][50];
int n, m, k;
int cnt;

void update(int x, int y, int dist) {
	if (x < 0 || x >= n || y < 0 || y >= m) return;

	cnt++;
	mat[x][y] = min(mat[x][y], dist);
}

int main() {
	setIO("blist");
	
	cin >> n >> m >> k;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			mat[i][j] = INT_MAX;
		}
	}


	for (int i = 0; i < k; i++) {
		int x, y, t;
		int dist = 0;
		cin >> x >> y >> t;
		x--;
		y--;

		if (t == 0) {
			int move = 1;
			int dist = 1;
			update(x, y, dist);
			while (move <= 50) {
				for (int j = 0; j < move; j++) {
					x--;
					dist++;
					update(x, y, dist);
				}
				for (int j = 0; j < move; j++) {
					y++;
					dist++;
					update(x, y, dist);
				}
				move++;
				for (int j = 0; j < move; j++) {
					x++;
					dist++;
					update(x, y, dist);
				}
				for (int j = 0; j < move; j++) {
					y--;
					dist++;
					update(x, y, dist);
				}
				move++;
			}
		}
		else {
			int move = 1;
			int dist = 1;
			update(x, y, dist);
			while (cnt <= n*m) {
				for (int j = 0; j < move; j++) {
					x--;
					dist++;
					update(x, y, dist);
				}
				for (int j = 0; j < move; j++) {
					y--;
					dist++;
					update(x, y, dist);
				}
				move++;
				for (int j = 0; j < move; j++) {
					x++;
					dist++;
					update(x, y, dist);
				}
				for (int j = 0; j < move; j++) {
					y++;
					dist++;
					update(x, y, dist);
				}
				move++;
			}
		}
	}

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cout << mat[i][j] << ' ';
		}
		cout << '\n';
	}
}