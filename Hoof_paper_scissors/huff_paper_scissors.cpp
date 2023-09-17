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
	setIO("hps");

	int n;
	cin >> n;
	int ans = 0;
	vector<int> h(n+1);
	vector<int> p(n+1);
	vector<int> s(n+1);
	for (int i = 1; i <= n; i++) {
		char x;
		cin >> x;
		h[i] = h[i-1];
		p[i] = p[i-1];
		s[i] = s[i-1];

		if (x == 'H')  {
			p[i]++;
		}
		else if (x == 'P') {
			s[i]++;
		}
		else {
			h[i]++;
		}
	}

	for (int i = 0; i <= n; i++) {
		int best = max(h[i] + p[n] - p[i], h[i] + s[n] - s[i]);
		best = max(best, p[i] + h[n] - h[i]);
		best = max(best, p[i] + s[n] - s[i]);
		best = max(best, s[i] + h[n] - h[i]);
		best = max(best, s[i] + p[n] - p[i]);

		ans = max(ans, best);

	}
	cout << ans << '\n';
}