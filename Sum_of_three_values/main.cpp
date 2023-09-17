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

    int n, x;
    cin >> n >> x;
    vector<pair<int, int>> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i].first;
        a[i].second = i;
    }
    sort(a.begin(), a.end());

    for (int i = 0; i < n; i++) {
        int l = 0, r = n-1;
        while (l != r) {
            int target = x - a[i].first;
            int val = a[l].first + a[r].first;
            if (val == target && l != i && r != i) {
                cout << a[i].second + 1 << ' ' << a[l].second + 1 << ' ' << a[r].second + 1 << '\n';
                return 0;
            }
            if (val < target) {
                l++;
            }
            else {
                r--;
            }
        }
    }
    cout << "IMPOSSIBLE" << '\n';
}