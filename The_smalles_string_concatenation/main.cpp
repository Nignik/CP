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

bool cmp (string& a, string& b) {
    return (a + b) < (b + a);
}

int main() {
	setIO("blist");

    int n;
    cin >> n;
    vector<string> a(n);
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        a[i] = s;
    }
    sort(a.begin(), a.end(), cmp);

    for (int i = 0; i < n; i++) {
        cout << a[i];
    }
}
