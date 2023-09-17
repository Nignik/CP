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
	setIO("reststops");

    int l, n, f, b;
    cin >> l >> n >> f >> b;

    vector<pair<int, int>> v(n);
    for (int i = 0; i < n; i++) {
        int x, c;
        cin >> x >> c;
        v[i] = {x, c};
    }
    ll advantage = f - b;

    ll ans = 0;
    ll prev = 0;
    for (int i = n-1; i >= 0; i--) {
        if (v[i].second > prev) {
            ans -= prev * v[i].first * advantage;
            ans += v[i].second * v[i].first * advantage;
            prev = v[i].second;
        }
    }

    cout << ans << '\n';
}