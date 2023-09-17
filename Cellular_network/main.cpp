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
    vector<int> cities(n);
    vector<int> towers(m);
    for (int i = 0; i < n; i++) {
        cin >> cities[i];
    }
    for (int i = 0; i < m; i++) {
        cin >> towers[i];
    }
    set<int> sc(cities.begin(), cities.end());
    set<int> st(towers.begin(), towers.end());
    cities.assign(sc.begin(), sc.end());
    towers.assign(st.begin(), st.end());
    int c = 0, t = 0;
    int max_r = 0;
    while (c < cities.size() && t < towers.size()) {
        if (t < m-1) {
            while (abs(cities[c] - towers[t]) > abs(cities[c] - towers[t+1]) || t > m-1) {
                t++;
            }
        }
        max_r = max(max_r, abs(cities[c] - towers[t]));
        c++;
    }

    cout << max_r << '\n';
}
