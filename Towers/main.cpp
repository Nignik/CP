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
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    multiset<int> max_cubes;
    max_cubes.insert(a[0]);
    int towers = 1;
    for (int i = 1; i < n; i++) {
        auto j = max_cubes.upper_bound(a[i]);
        if (j == max_cubes.end()) {
            towers++;
        }
        else {
            max_cubes.erase(j);
        }
        max_cubes.insert(a[i]);
    }

    cout << towers << '\n';
}
