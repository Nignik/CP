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

	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		string s;
		cin >> s;
		vector<int> a(n+1);
		for (int i = 1; i <= n; i++) {
			a[i] = s[i-1] - '0';
			a[i] += a[i-1];
		}

		map<int, ll> m;
		ll cnt = 0;
		for (int i = 0; i <= n; i++) {
			m[a[i] - i]++;
		}
		for (auto x : m) {
			cnt += x.second * (x.second - 1) / 2;
		}
		cout << cnt << '\n';
	}
}