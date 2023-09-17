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

int cnt = 0;
int M;

void add_element(int x, map<int, int>& m) {
    for (int i = 1; i <= sqrt(x); i++) {
        if (x % i == 0) {
            if (x / i == i && x / i <= M) {
                if (m[i] == 0) cnt++;
                m[i]++;
            }
            else {
                if (m[i] == 0 && i <= M) cnt++;
                if (m[x/i] == 0 && x / i <= M) cnt++;
                m[i]++;
                m[x/i]++;
            }
        }
    }
}
void erase_element(int x, map<int, int>& m) {
    for (int i = 1; i <= sqrt(x); i++) {
        if (x % i == 0) {
            if (x / i == i && x / i <= M) {
                if (m[i] == 1) cnt--;
                m[i]--;
            }
            else {
                if (m[i] == 1 && i <= M) cnt--;
                if (m[x/i] == 1 && x / i <= M) cnt--;
                m[i]--;
                m[x/i]--;
            }
        }
    }
}

int main() {
	setIO("blist");

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n >> M;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        sort(a.begin(), a.end());

        map<int, int> m;
        int ans = INT_MAX;
        int l = 0, r = 0;
        add_element(a[0], m);
        while (l < n && r < n) {
            if (cnt == M) {
                ans = min(ans, a[r] - a[l]);
                erase_element(a[l], m);
                l++;
            }
            else {
                r++;
                add_element(a[r], m);
            }
        }

        if (ans == INT_MAX) {
            cout << -1 << '\n';
        }
        else {
            cout << ans << '\n';
        }
        cnt = 0;
    }
}