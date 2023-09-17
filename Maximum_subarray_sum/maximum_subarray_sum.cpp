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
	vector<ll> a(n+1);
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		a[i] += a[i-1];
	}

	ll low = INT_MAX;

	ll high = -INT_MAX;
	for (int i = 0; i <= n; i++) {
		high = max(high, a[i] - low);
		low = min(low, a[i]);
	}

	cout << high << '\n';
}