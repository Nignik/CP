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

struct f {
    int h, w;
    int id;
};

bool height(const f& a, const f& b) {
    if (a.h == b.h) return a.w > b.w;
    return a.h < b.h;
}
bool width(const f& a, const f& b) {
    if (a.w == b.w) return a.h < b.h;
    return a.w < b.w;
}

int main() {
	setIO("blist");

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<f> a(n);
        for (int i = 0; i < n; i++) {
            int h, w;
            cin >> h >> w;
            a[i] = {max(h, w), min(h, w), i};
        }
        sort(a.begin(), a.end(), height);

        map<int, int> ans;
        ans[a[0].id] = -1;
        f smallest = a[0];
        for (int i = 1; i < n; i++) {
            if (a[i].w > smallest.w) {
                ans[a[i].id] = smallest.id + 1;
            }
            else{
                ans[a[i].id] = -1;
                smallest = a[i];
            }
        }

        for (const auto& x : ans) {
            cout << x.second << ' ';
        }
        cout <<  '\n';
    }
}
