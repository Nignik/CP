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

	int n;
	cin >> n;
	vector<int> a(n);
	vector<int> b(n);
	
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	int ans = n-1;
	for (int i = n-2; i >= 0; i--) {
		if (a[i] < a[i+1]) {
			ans = i;
		}
		else {
			break;
		}
	}

	cout << ans;
}