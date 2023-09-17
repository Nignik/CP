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

    int n, m, k;
    cin >> n >> m >> k;
    vector<int> a(n);
    vector<int> b(m);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0;i < m; i++) {
        cin >> b[i];
    }

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    int ans = 0;
    int hi = 0, lo = 0;
    while (hi < n && lo < m) {
        if (b[lo] >= a[hi] - k &&  b[lo] <= a[hi] + k) {
            ans++;
            hi++;
            lo++;
        }
        else if (b[lo] < a[hi] - k) {
            lo++;
        }
        else if (b[lo] > a[hi] + k){
            hi++;
        }
    }

    cout << ans << '\n';
}
