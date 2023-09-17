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
	setIO("highcard");

    int n;
    cin >> n;
    set<int> s;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<int> b = a;
    sort(b.begin(), b.end());
    for (int i = 1, j = 0; i <= n*2; i++) {
        if (i != b[j]) {
            s.insert(i);
        }
        else {
            j++;
        }
    }

    int ans = 0;
    for (int i = 0; i < n; i++) {
        auto x = s.upper_bound(a[i]);
        if (x == s.end()) {
            s.erase(s.begin());
        }
        else {
            s.erase(x);
            ans++;
        }
    }

    cout << ans << '\n';
}
