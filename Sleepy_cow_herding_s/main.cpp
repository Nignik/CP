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
	setIO("herding");

    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    sort(a.begin(), a.end());
    int min_moves = 0;

    if (a[n-2] - a[0] == n-2 && a[n-1] - a[n-2] > 2) min_moves = 2;
    else if (a[n-1] - a[n] == n-2 && a[1] - a[0] > 2) min_moves = 2;
    else {
        int last_cow = 0;
        for (int i = 0; i < n; i++) {
            while (last_cow+1 < n && a[last_cow+1] - a[i] < n) {
                last_cow++;
            }
            min_moves = min(min_moves, n - (last_cow - i + 1));
        }
    }

    int gap = 0;
    for (int i = 1; i < n; i++) gap += a[i] - a[i-1] - 1;
    int max_moves = max(gap - (a[1] - a[0] - 1), gap - (a[n-1] - a[n-2] - 1));
    cout << min_moves << '\n' << max_moves << '\n';
}
