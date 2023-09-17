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

int main() {
	setIO("blist");

	int n;
    cin >> n;
    string s;
    cin >> s;
    int q;
    vector<int> mask(26);
    cin >> q;
    for (int i = 0; i < n; i++) {
        mask[s[i] - 'a']++;
    }
    for (int i = 0; i < q; i++) {
        int m;
        char c;

        cin >> m >> c;

        int len = min(n - mask[c - 'a'], m);
        int ans = 0;
        int cnt = 0;
        int l = 0, r = 0;
        if (s[0] != c) cnt++;
        while (l < n && r < n) {
            if (cnt == len) {
                ans = max(ans, r - l + 1);
            }
            if (cnt <= len) {
                r++;
                if (s[r] != c) {
                    cnt++;
                }
            }
            else if (cnt > len) {
                if (s[l] != c) {
                    cnt--;
                }
                l++;
            }
        }

        cout << ans << '\n';
    }
}
