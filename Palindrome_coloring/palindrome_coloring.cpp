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

	int t;
	cin >> t;
	while (t--) {
		int n, k;
		cin >> n >> k;
		string s;
		cin >> s;
		vector<int> a(26);
		for (int i = 0; i < n; i++) {
			a[s[i] - 'a']++;
		}

		int odd = 0;
		int even = 0;
		for (int i = 0; i < 26; i++) {
			if (a[i] % 2) {
				a[i] -= 1;
				odd++;
			}
			even += a[i] / 2;
		}

		int smallest = 2 * (even / k);
		odd += 2 * (even % k);

		if (odd >= k) {
			smallest++;
		}
		
		cout << smallest << '\n';
	}
}