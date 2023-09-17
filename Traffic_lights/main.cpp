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

	int x, n;
    cin >> x >> n;
    set<int> s;
    s.insert(0);
    s.insert(x);
    map<int, int> m;
    m[x] = 1;

    multiset<int> ans;
    ans.insert(x);
    for (int i = 0; i < n; i++) {
        int p;
        cin >> p;
        s.insert(p);
        auto p1 = s.lower_bound(p);
        auto l = --p1;
        auto r = ++p1;
        r++;

        ans.erase(ans.find(*r - *l));
        ans.insert(p - *l);
        ans.insert(*r - p);

        cout << *ans.rbegin() << ' ';
    }
}
