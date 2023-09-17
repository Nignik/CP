#include <bits/stdc++.h>

using namespace std;

void setIO(string s) {
	ios_base::sync_with_stdio(0); cin.tie(0);
	if (fopen((s+".in").c_str(), "r")){
		freopen((s+".in").c_str(),"r",stdin);
		freopen((s+".out").c_str(),"w",stdout);
	}
}

const int N = 105;
vector<int> a[N];
vector<int> b(N);
bool visited[N];

void dfs(int s) {
	/*if (visited[s]) return;
	visited[s] = true;*/

	for (auto u : a[s]) {
		b[u]++;
		dfs(u);
	}
}

int main() {
	setIO("factory");

	int n;
	cin >> n;


	for (int i = 0; i < n-1; i++) {
		int x, y;
		cin >> x >> y;
		a[x].push_back(y);
	}

	for (int i = 1; i <= n; i++) {
		dfs(i);
	}
	

	for (int i = 0; i < N; i++) {
		if (b[i] == n-1) {
			cout << i << '\n';
			return 0;
		}
	}

	cout << -1 << '\n';
}

