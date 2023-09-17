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
	setIO("lemonade");

    int n;
    cin >> n;
    deque<int> a;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        a.push_back(x);
    }
    sort(a.begin(), a.end());

    int ans = 0;
    for (int i = 0; i < n; i++) {
        int cow = a.front();

        if (cow < ans) {
            a.pop_front();
        }
        else {
            a.pop_back();
            ans++;
        }
    }

    cout << ans << '\n';
}
