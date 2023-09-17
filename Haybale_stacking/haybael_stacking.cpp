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

int ans[1000000];

int main() {
	setIO("blist");

	int n, k;
	cin >> n >> k;
	vector<int> a(n+1);

	for (int i = 0; i < k; i++) {
		int l, r;
		cin >> l >> r;
		l--;
		r--;
		a[l]++;
		a[r+1]--;
	}

	int sum = 0;
	for (int i = 0; i < n; i++) {
		sum += a[i];
		ans[i] = sum;
	}
	sort(ans, ans + n);
	cout << ans[n/2] << '\n';
}