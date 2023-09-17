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
	setIO("div7");

	int n;
	cin >> n;
	vector<ll> a(n + 1);
	vector<int> first(7, -1);
	first[0] = 0;

	int rem = 0;
	int best = 0;
	for (int i = 1; i <= n; i++) {
		int x;
		cin >> x;

		rem = (rem + x) % 7;
		if (first[rem] == -1) {
			first[rem] = i;
		}
		else {
			best = max(best, i - first[rem]);
		}
	}

	cout << best << '\n';
}