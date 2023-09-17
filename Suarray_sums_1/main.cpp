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
    ll x;
    cin >> n >> x;
    vector<ll> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int l = 0, r = 0;
    ll sum = a[0];
    ll cnt = 0;
    while ((l < n && r < n)) {
        if (l > r) {
            r++;
            sum += a[r];
        }
        if (sum == x) {
            cnt++;
            sum -= a[l];
            l++;
            r++;
            sum += a[r];
        }
        else if (sum < x) {
            r++;
            sum += a[r];
        }
        else if (sum > x){
            sum -= a[l];
            l++;
        }
    }

    cout << cnt << '\n';
}
