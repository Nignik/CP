#include <bits/stdc++.h>

using namespace std;

void setIO(string s) {
	ios_base::sync_with_stdio(0); cin.tie(0);
	if (fopen((s+".in").c_str(), "r")){
		freopen((s+".in").c_str(),"r",stdin);
		freopen((s+".out").c_str(),"w",stdout);
	}
}

typedef long long ll;

int main() {
	setIO("blist");

	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector<ll> h(n);
		for (int i = 0; i < n; i++) {
			cin >> h[i];
		}

		ll diff = 0;
		bool valid = true;

		for (int i = 0; i < n-1; i++) {
			if (h[i] < h[i+1]) {
				if (i+2 > n-1) {
					valid = false;
					break;
				}

				ll x = h[i+1] - h[i];
				h[i+1] -= x;
				h[i+2] -= x;

				if (h[i+2] < 0) {
					valid = false;
					break;
				}
				diff += x * 2;
			}
			else if (h[i] > h[i+1]) {
				if (i % 2 == 0) {
					valid = false;
					break;
				}

				ll x = h[i] - h[i+1];
				diff += x * (i+1);
			}
			
		}

		if (valid) {
			cout << diff << '\n';
		}
		else {
			cout << -1 << '\n';
		}
		
	}
}