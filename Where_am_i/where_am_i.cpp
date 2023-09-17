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
	setIO("whereami");

	int n;
	cin >> n;

	string s;
	cin >> s;

	for (int i = 1; i < 101; i++) {
		set<string> m;
		bool valid = true;
		for (int j = 0; j < n; j++) {
			if (m.find(s.substr(j, i)) != m.end()) {
				valid = false;
				break;
			}
			m.insert(s.substr(j, i));
		}
		if (valid) {
			cout << i << '\n';
			return 0;
		}
	}
}