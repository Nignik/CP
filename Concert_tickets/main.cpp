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

    int n, m;
    cin >> n >> m;
    multiset<int> h;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        h.insert(x);
    }
    for (int i = 0; i < m; i++) {
        int x;
        cin >> x;
        if (h.size() == 0)  {
            cout << -1 << '\n';
            continue;
        }
        auto paid = h.lower_bound(x);
        if (paid == h.end()) {
            paid--;
            cout << *paid << '\n';
            h.erase(paid);
            continue;
        }
        if (*paid > x) {
            if (paid != h.begin()) {
                paid--;
            }
            else {
                cout << -1 << '\n';
                continue;
            }
        }
        cout << *paid << '\n';
        h.erase(paid);
    }
}
