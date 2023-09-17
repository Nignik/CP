#include <bits/stdc++.h>

using namespace std;

void setIO(string s) {
	ios_base::sync_with_stdio(0); cin.tie(0);
	if (fopen((s+".in").c_str(), "r")){
		freopen((s+".in").c_str(),"r",stdin);
		freopen((s+".out").c_str(),"w",stdout);
	}
}

typedef long long ll;

int main() {
	setIO("blist");

	int n, q;
	cin >> n >> q;
	vector<ll> a(n);
	cin >> a[0];
	for (int i = 1; i < n; i++) {
		int x;
		cin >> x;
		a[i] = a[i-1] + x;
	}

	for (int i = 0; i < q; i++) {
		int l, r;
		cin >> l >> r;
		ll sum_l = l-1 >= 0 ? a[l-1] : 0;
		ll sum_r = a[max(0, r-1)];
		cout << sum_r - sum_l << '\n';
	}
}