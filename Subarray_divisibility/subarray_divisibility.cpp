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

	int n;
	cin >> n;
	vector<int> a(n + 1);
	map<ll, int> m;
	for (int i = 1; i <= n; i++) {
		int x;
		cin >> x;
		a[i] = ((x + a[i - 1]) % n + n) % n;
	}

	
	ll ans = 0;
	for (int i = 0; i <= n; i++) {
		ans += m[a[i]];
		m[a[i]]++;
	}

	cout << ans << '\n';
}