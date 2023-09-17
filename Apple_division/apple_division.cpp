#include <bits/stdc++.h>

using namespace std;

void setIO(string s) {
	ios_base::sync_with_stdio(0); cin.tie(0);
	if (fopen((s+".in").c_str(), "r")){
		freopen((s+".in").c_str(),"r",stdin);
		freopen((s+".out").c_str(),"w",stdout);
	}
}

int n;
long long sum = 0;
long long ans = INT_MAX;
vector<int> p(22);
vector<int> subset;

void search(int k) {
	if (k == n) {
		long long a = 0, b = 0;
		for (int i = 0; i < subset.size(); i++) {
			a += subset[i];
		}
		b = sum - a;
		ans = min(ans, abs(b - a));
	}
	else {
		search(k + 1);
		subset.push_back(p[k]);
		search(k + 1);
		subset.pop_back();
	}
}

int main() {
	setIO("blist");

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> p[i];
		sum += p[i];
	}
	search(0);
	cout << ans << '\n';
}