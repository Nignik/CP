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
    cin >> n;
    multiset<pair<int, int>> m;
    for (int i = 0 ; i < n; i++) {
        int x, y;
        cin >> x >> y;
        m.insert({x, y});
    }

    map<int, int> ops;
    int current_rooms = 0;
    int max_rooms = 0;
    vector<int> ans;
    pair<int, int> prev = {-1, 0};
    for (const auto& i : m) {
        if (i.first != prev.first && (prev.first == prev.second)) {
            current_rooms -= ops[prev.first];
        }
        else if (i.first == prev.first && (prev.first == prev.second)) {

        }
        else {
            current_rooms -= ops[i.first];
        }
        current_rooms++;

        auto x = m.upper_bound(make_pair(i.second, 0));
        if (x != m.end()) {
            ops[x->first]++;
        }

        ans.push_back(current_rooms);
        max_rooms = max(max_rooms, current_rooms);
        prev = i;
    }

    cout << max_rooms << '\n';
    for (int i = 0; i < n; i++) {
        cout << ans[i] << ' ';
    }
}