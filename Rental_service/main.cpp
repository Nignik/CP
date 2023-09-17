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
	setIO("rental");

    int n, m, r;
    int total_cows = 0;
    cin >> n >> m >> r;
    vector<int> cows(n);
    for (int i = 0; i < n; i++) {
        cin >> cows[i];
        total_cows += cows[i];
    }
    vector<pair<int, int>> stores(m);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        stores[i] = make_pair(b, a);
    }
    vector<int> rents(r);
    for (int i = 0; i < r; i++) {
        cin >> rents[i];
    }

    sort(stores.rbegin(), stores.rend());
    sort(cows.rbegin(), cows.rend());
    sort(rents.rbegin(), rents.rend());

    ll ans = 0;
    int store_at = 0;
    int rent_at = 0;
    int cow_at = 0;
    while (cow_at < n) {
        int cow = cows[cow_at];
        int money = 0;
        int curr_store = store_at;
        int last = 0;

        while (curr_store < m) {
            int sold = min(stores[curr_store].second, cow);
            money += stores[curr_store].first * sold;
            cow -= sold;

            if (cow == 0) {
                last = sold;
                break;
            }
            else {
                curr_store++;
            }
        }

        if (rent_at >= r || money > rents[rent_at]) {
            ans += money;
            store_at = curr_store;
            if (store_at < m) {
                stores[store_at].second -= last;
            }
            cow_at++;
        }
        else {
            ans += rents[rent_at];
            n--;
            rent_at++;
        }
    }

    cout << ans << '\n';
}
