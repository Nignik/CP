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
	string s;
	cin >> s;
	
	int ans = 0;
	for (int i = n-2; i >= 0; i-=2) {
		string sub = s.substr(i, 2);
		if ((sub == "GH" && ans % 2 == 0) || (sub == "HG" && ans % 2 == 1)) {
			ans++;
		}
	}
	
	cout << ans << '\n';
}