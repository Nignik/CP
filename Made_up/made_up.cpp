#include <bits/stdc++.h>

using namespace std;

void setIO(string s) {
	ios_base::sync_with_stdio(0); cin.tie(0);
	if (fopen((s+".in").c_str(), "r")){
		freopen((s+".in").c_str(),"r",stdin);
		freopen((s+".out").c_str(),"w",stdout);
	}
}

const int N = 10e5+5;

int main() {
	setIO("blist");

	int n;
	cin >> n;
	vector<int> a(N);
	vector<int> b(n+1);
	vector<int> c(n+1);
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		a[x]++;
	}
	for (int i = 1; i <= n; i++) {
		cin >> b[i];
	}
	for (int i = 1; i <= n; i++) {
		cin >> c[i];
	}

	long long ans = 0;
	for (int j = 1; j <= n; j++) {
		int num = b[c[j]];
		
		ans += a[num];
	}

	cout << ans << '\n';
}