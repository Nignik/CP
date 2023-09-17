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

    int n, k;
    cin >> n >> k;
    vector<pair<int, int>> a(n);
    multiset<pair<int, int>> movies;
    int cnt = k;
    for (int i = 0; i < n; i++) {
        cin >> a[i].first >> a[i].second;
    }
    sort(a.begin(), a.end());

    int ans = 0;
    for (int i = 0; i < n; i++) {
        auto front = *movies.begin();

        while (!movies.empty() && front.first <= a[i].first) {
            auto front_ptr = movies.begin();
            movies.erase(front_ptr);
            ans++;
            front = *movies.begin();
        }

        cnt = movies.size();

        movies.emplace(a[i].second, a[i].first);
        auto back_ptr = movies.end();
        if (!movies.empty()) {
            back_ptr--;
        }
        if (cnt == k) {
            movies.erase(back_ptr);
        }
        else {
            cnt = movies.size();
        }
    }
    ans += movies.size();

    cout << ans << '\n';
}