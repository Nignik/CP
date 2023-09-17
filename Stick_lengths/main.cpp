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

    sort(a.begin(), a.end());
    int median;
    if (n % 2 == 0) {
        median = (a[n/2 - 1] + a[n/2]) / 2;
    }
    else {
        median = a[n/2];
    }

    ll total_diff = 0;
    for (int i = 0; i < n; i++) {
        total_diff += abs(a[i] - median);
    }

    cout << total_diff << '\n';
}