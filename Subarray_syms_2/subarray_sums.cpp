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

	int n, x;
	cin >> n >> x;
	vector<ll> a(n+1);
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		a[i] += a[i-1];
	}

	ll cnt = 0;
	map<ll, int> search;
	for (int i = 0; i <= n; i++) {
		ll y = x + a[i];

		if (search.count(a[i]) != 0) {
			cnt += search[a[i]];
		}

		if (search.count(y) == 0) {
			search[y] = 1;
		}
		else {
			search[y]++;
		}
	}

	cout << cnt << '\n';
}