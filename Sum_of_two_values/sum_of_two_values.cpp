#include <bits/stdc++.h>

using namespace std;

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
	vector<int> a(n);
	map<int, int> m;
	map<int, int> dup;

	for (int i = 0; i < n; i++) {
		cin >> a[i];
		if (m.count(a[i])) {
			dup[a[i]] = m[a[i]];
		}
		m[a[i]] = i+1;
	}

	sort(a.begin(), a.end());
	int l = 0, r = n-1;
	while(l < r) {
		if (a[l] + a[r] == x) {
			if (a[l] == a[r]) {
				cout << m[a[l]] << ' ' << dup[a[r]] << '\n';
			}
			else {
				cout << m[a[l]] << ' ' << m[a[r]] << '\n';
			}
			return 0;
		}
		else if (a[l] + a[r] < x) {
			l++;
		}
		else {
			r--;
		}
	}

	cout << "IMPOSSIBLE" << '\n';
}