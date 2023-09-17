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
	setIO("cardgame");

    int n;
    cin >> n;
    vector<int> a1;
    vector<int> a2;
    vector<int> b1;
    vector<int> b2;

    set<int> played1;
    set<int> played2;
    for (int i = 0; i < n/2; i++) {
        int x;
        cin >> x;
        played1.insert(x);
    }
    for (int i = 0; i < n/2; i++) {
        int x;
        cin >> x;
        played2.insert(x);
    }

    for (int i = n*2; i > 0; i--) {
        if (played1.find(i) == played1.end() && played2.find(i) == played2.end()) {
            if (a1.size() >= n/2) {
                a2.push_back(i);
            }
            else {
                a1.push_back(i);
            }
        }
        else if (played1.find(i) == played1.end()){
            b2.push_back(i);
        }
        else if (played2.find(i) == played2.end()){
            b1.push_back(i);
        }
    }
    sort(a1.begin(), a1.end());
    sort(b1.begin(), b1.end());
    sort(b2.rbegin(), b2.rend());

    int l = 0, r = 0;
    int ans = 0;
    set<int> unused;
    while (l < n/2 && r < n/2) {
        if (a1[l] < b1[r]) {
            l++;
        }
        else {
            l++;
            r++;
            ans++;
        }
    }
    while (l < n/2) {
        a2.push_back(a1[l]);
        l++;
    }

    sort(a2.rbegin(), a2.rend());
    r = 0;
    l = 0;
    while (l < n/2 && r < n/2) {
        if (a2[l] > b2[r]) {
            l++;
        }
        else {
            l++;
            r++;
            ans++;
        }
    }

    cout << ans << '\n';
}