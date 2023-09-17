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
	setIO("breedflip");

	int n;
	cin >> n;
	string s1, s2;
	cin >> s1 >> s2;

	int cnt = 0;;
	int curr = 0;
	for (int i = 0; i < n; i++) {
		if (s2[i] == s1[i]) {
			cnt += curr;
			curr = 0;
		}
		else {
			curr = 1;
		}
	}

	cout << cnt;
} 