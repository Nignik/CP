#include <bits/stdc++.h>

using namespace std;

void setIO(string s) {
	ios_base::sync_with_stdio(0); cin.tie(0);
	if (fopen((s+".in").c_str(), "r")){
		freopen((s+".in").c_str(),"r",stdin);
		freopen((s+".out").c_str(),"w",stdout);
	}
}

long long max(long long a, long long b) {
	if (a >= b) {
		return a;
	}
	else {
		return b;
	}
}

int main() {
	setIO("cowqueue");

	int n;
	cin >> n;
	vector<pair<long long, long long>> q(n);
	for (int i = 0; i < n; i++) {
		long long t, qt;
		cin >> t >> qt;
		q[i] = make_pair(t, qt);
	}

	sort(q.begin(), q.end());
	long long qt = 0;

	for (int i = 1; i < n; i++) {
		q[i].first += max(0, q[i-1].first + q[i-1].second - q[i].first);
	}

	cout << q[n-1].first + q[n-1].second << '\n';
}