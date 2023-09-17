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
	vector<int> p(n+2);
	vector<int> s(n+2);
	vector<int> a(n+1);
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}

	p[0] = 0;
	s[n+1] = 0;

	for (int i = 1; i <= n; i++) {
		p[i] = gcd(p[i-1], a[i]);
	}
	for (int i = n; i >= 1; i--) {
		s[i] = gcd(s[i+1], a[i]);
	}

	int ans = 0;
	for (int i = 1; i <= n; i++) {
		ans = max(ans, gcd(p[i-1], s[i+1]));
	}

	cout << ans << '\n';
}