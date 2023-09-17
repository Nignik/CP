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

const int N = 2001;

char grid[N][N];
int p1[N][N];
int p2[N][N];
int p3[N][N];


int main() {
	setIO("blist");

	int n, m, q;
	cin >> n >> m >> q;
	vector<vector<int>> a(n, vector<int>(n));
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> grid[i][j];

			p1[i][j] = (grid[i][j] == '1') + p1[i-1][j] + p1[i][j-1] - p1[i-1][j-1];
			p2[i][j] = (grid[i][j] == '1' && grid[i-1][j] == '1') + p2[i-1][j] + p2[i][j-1] - p2[i-1][j-1];
			p3[i][j] = (grid[i][j] == '1' && grid[i][j-1] == '1') + p3[i-1][j] + p3[i][j-1] - p3[i-1][j-1];

		}
	}



	for (int i = 0; i < q; i++) {
		int a, b, c, d;
		cin >> a >> b >> c >> d;

		int x = p1[c][d] + p1[a-1][b-1] - p1[a-1][d] - p1[c][b-1];
		int y = p2[c][d] + p2[a][b-1] - p2[a][d] - p2[c][b-1];
		int z = p3[c][d] + p3[a-1][b] - p3[a-1][d] - p3[c][b];

		cout << x - y - z << '\n';
	}





}