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
	setIO("diamond");

	int n, k;
    cin >>  n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());

    int l = 0, r = 0;
    int ans = 0;

    vector<int> box(n);
    while (l < n && r < n) {
        if (a[r] - a[l] <= k) {
            box[r] = r - l + 1;
            r++;
        }
        else {
            l++;
        }
    }

    vector<int> p(n+1);
    p[0] = 1;
    for (int i = 1; i < n; i++) {
        p[i] = max(p[i-1], box[i]);
    }

    for (int i = 0; i < n; i++) {
        if (box[i] > i) {
            ans = max(ans, p[i]);
        }
        else {
            ans = max(ans, box[i] + p[i - box[i]]);
        }
    }
    cout << ans << '\n';
}