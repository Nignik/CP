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
	setIO("mountains");

    int n;
    cin >> n;
    vector<pair<int, int>> a(n);
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        a[i] = {x - y, x + y};
    }
    sort(a.begin(), a.end());

    int ans = 0;
    pair<int, int> curr_mnt = a[0];
    for (int i = 1; i < n; i++) {
        if (a[i].first <= curr_mnt.second && a[i].second <= curr_mnt.second) {
            ans++;
        }
        else if (a[i].second > curr_mnt.second) {
            if (a[i].first == curr_mnt.first && a[i].second > curr_mnt.second) ans++;
            curr_mnt = a[i];
        }
    }

    cout << n - ans << '\n';
}