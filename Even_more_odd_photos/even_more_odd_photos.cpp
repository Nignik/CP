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
	int odd = 0, even = 0;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		if (x % 2 == 0) {
			even++;
		}
		else {
			odd++;
		}
	}

	while (odd > even) {
		odd -= 2;
		even++;
	}

	if (even > odd + 1) {
		even = odd + 1;
	}

	cout << odd + even << '\n';
}