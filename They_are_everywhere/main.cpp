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
    string a;
    set<char> o;
    cin >> a;
    for (int i = 0; i < n; i++) {
        o.insert(a[i]);
    }

    set<char> s;
    map<char, int> m;
    int ans = INT_MAX;
    int l = 0, r = 0;
    s.insert(a[0]);
    m[a[0]]++;
    while (l < n && r < n) {
        if (s.size() == o.size()) {
            ans = min(ans, r - l + 1);
            m[a[l]]--;
            if (m[a[l]] == 0) {
                s.erase(s.find(a[l]));
            }
            l++;
        }
        else {
            r++;
            s.insert(a[r]);
            m[a[r]]++;
        }
    }

    cout << ans << '\n';
}
