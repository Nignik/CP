#include <bits/stdc++.h>

using namespace std;

void setIO(string s) {
	ios_base::sync_with_stdio(0); cin.tie(0);
	if (fopen((s+".in").c_str(), "r")){
		freopen((s+".in").c_str(),"r",stdin);
		freopen((s+".out").c_str(),"w",stdout);
	}
}

int N = 8;
int ans = 0;

vector<vector<int>> board(N, vector<int>(N));
vector<int> col(N);
vector<int> row(N);
vector<int> diag1(N*2);
vector<int> diag2(N*2);

void search(int n) {
	if (n == N) {
		ans++;
	}
	else {
		for (int i = 0; i < N; i++) {
			if (col[i] || diag1[i+n] || diag2[i-n+N-1] || board[i][n]) continue;
			
			col[i] = diag1[i+n] = diag2[i-n+N-1] = 1;
			search(n + 1);
			col[i] = diag1[i+n] = diag2[i-n+N-1] = 0;
		}
	}
}

int main() {
	setIO("blist");

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			char field;
			cin >> field;
			if (field == '.') board[i][j] = 0;
			else if (field == '*') board[i][j] = 1;
		}
	}

	search(0);
	cout << ans << '\n';
}