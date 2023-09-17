
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
    set<int> leave;
    set<int> arrive;
    vector<int> a(n*2);
    for (int i = 0; i < n*2; i++) {
        cin >> a[i];
        if (i % 2) {
            leave.insert(a[i]);
        }
        else {
            arrive.insert(a[i]);
        }
    }

    sort(a.begin(), a.end());
    map<int, int> m;
    for (int i = 0; i < n*2; i++) {
        m[i] = a[i];
    }


    int sum = 0;
    int best = 0;
    for (const auto& x : m) {
        if (arrive.find(x.second) != arrive.end()) {
            sum++;
        }
        else {
            sum--;
        }
        best = max(best, sum);
    }

    cout << best << '\n';
}