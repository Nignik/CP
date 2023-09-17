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
bool cmp(pair<int, int> a, pair<int, int> b) {
    if (a.second == b.second) return a.first < b.first;
    return a.second < b.second;
}

int main() {
	setIO("split");

    int n;
    cin >> n;
    vector<pair<int, int>> cows(n);
    for (int i = 0; i < n; i++) {
        cin >> cows[i].first >> cows[i].second;
    }

    sort(cows.begin(), cows.end());
    auto x_sort = cows;
    sort(cows.begin(), cows.end(), cmp);
    auto y_sort = cows;

    ll bound_left = x_sort[0].first;
    ll bound_down = y_sort[0].second;
    ll bound_right = x_sort[n-1].first;
    ll bound_up = y_sort[n-1].second;

    ll ans = LLONG_MAX;
    for (int i = 0; i < n-1; i++)  {
        ll x1, x2;
        x1 = x_sort[i].first;
        x2 = x_sort[i+1].first;

        if (x1 == x2) {
            continue;
        }

        ll y1_left, y2_left;
        for (int j = 0; j < n; j++) {
            if (y_sort[j].first <= x1) {
                y1_left = y_sort[j].second;
                break;
            }
        }
        for (int j = n-1; j >= 0; j--) {
            if (y_sort[j].first <= x1) {
                y2_left = y_sort[j].second;
                break;
            }
        }

        ll y1_right, y2_right;
        for (int j = 0; j < n; j++) {
            if (y_sort[j].first >= x2) {
                y1_right = y_sort[j].second;
                break;
            }
        }
        for (int j = n-1; j >= 0; j--) {
            if (y_sort[j].first >= x2) {
                y2_right = y_sort[j].second;
                break;
            }
        }

        ans = min(ans, (x1 - bound_left) * (y2_left - y1_left) + (bound_right - x2) * (y2_right - y1_right));
    }
    for (int i = 0; i < n-1; i++)  {
        ll y1, y2;
        y1 = y_sort[i].second;
        y2 = y_sort[i+1].second;
        if (y1 == y2) {
            continue;
        }

        ll x1_left, x2_left;
        for (int j = 0; j < n; j++) {
            if (x_sort[j].second <= y1) {
                x1_left = x_sort[j].first;
                break;
            }
        }
        for (int j = n-1; j >= 0; j--) {
            if (x_sort[j].second <= y1) {
                x2_left = x_sort[j].first;
                break;
            }
        }

        ll x1_right, x2_right;
        for (int j = 0; j < n; j++) {
            if (x_sort[j].second >= y2) {
                x1_right = x_sort[j].first;
                break;
            }
        }
        for (int j = n-1; j >= 0; j--) {
            if (x_sort[j].first >= y2) {
                x2_right = x_sort[j].first;
                break;
            }
        }

        ans = min(ans, (y1 - bound_down) * (x2_left - x1_left) + (bound_up - y2) * (x2_right - x1_right));
    }

    ans = (ll)(x_sort[n-1].first - bound_left) * (ll)(y_sort[n-1].second - bound_down) - ans;

    cout << abs(ans) << '\n';
}
