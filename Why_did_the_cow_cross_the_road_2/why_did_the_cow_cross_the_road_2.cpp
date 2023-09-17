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
	setIO("maxcross");

	int n, k, b;
	cin >> n >> k >> b;

	vector<int> a(n+1);
	for (int i = 1; i <= n; i++) {
		int x;
		cin >> x;
		a[x] = -1;
	}

	vector<int> p(n+1);
	for (int i = 1; i <= n; i++ ){
		p[i] = p[i-1];

		if (a[i] == -1) {
			continue;
		}
		else {
			p[i]++;
		}
	}

	int best = 0;
	for (int i = 1; i <= n - k + 1; i++) {
		best = max(best, p[i+k-1] - p[i] + 1);
	}

	cout << k - best << '\n';
}