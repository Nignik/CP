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
	setIO("bcount");

	int n, q;
	cin >> n >> q;
	vector<vector<int>> v(n+1, vector<int>(3));

	for (int i = 1; i <= n; i++) {
		int x;
		cin >> x;
		v[i][0] = v[i-1][0];
		v[i][1] = v[i-1][1];
		v[i][2] = v[i-1][2];
		v[i][x-1]++;
	}

	for (int i = 0; i < q; i++) {
		int l, r;
		cin >> l >> r;
		l--;
		cout << v[r][0] - v[l][0] << ' ' << v[r][1] - v[l][1] << ' ' << v[r][2] - v[l][2] << '\n';
	}
}