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
	setIO("pairup");

    int n;
    cin >> n;
    map<int, int> m;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        a[i] = y;
        m[y] = x;
    }
    sort(a.begin(), a.end());

    int l = 0, r = n-1;
    int ans = 0;
    while (l < r) {
        ans = max(ans, a[l] + a[r]);
        if (m[a[l]] > m[a[r]]) {
            m[a[l]] -= m[a[r]];
            r--;
        }
        else if (m[a[l]] < m[a[r]]) {
            m[a[r]] -= m[a[l]];
            l++;
        }
        else {
            l++;
            r--;
        }
    }

    cout << ans << '\n';
}