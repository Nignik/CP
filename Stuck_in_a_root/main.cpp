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

struct Cow {
    int x, y;
    int id;
    char dir;

    bool operator<(const Cow& a) {
        if (x != a.x) return x < a.x;
        return y < a.y;
    }
};

bool cmp(const Cow& a, const Cow& b) {
    if (a.y != b.y) return a.y < b.y;
    return a.x < b.x;
}

vector<int> visited;
vector<set<int>> ans;

int main() {
	setIO("blist");

	int n;
    cin >> n;
    visited.resize(n);
    ans.resize(n);
    vector<Cow> X, Y;
    for (int i = 0; i < n; i++) {
        char c;
        int x, y;
        cin >> c >> x >> y;

        if (c == 'N') {
            Y.push_back({x, y, i, c});
        }
        else if (c == 'E') {
            X.push_back({x, y, i, c});
        }
    }

    sort(Y.begin(), Y.end());
    sort(X.begin(), X.end(), cmp);

    set<int> stopped_X;
    set<int> stopped_Y;
    vector<int> ans_int(n);
    for (int i = 0; i < Y.size(); i++) {
        for (int j = 0; j < X.size(); j++) {
            if (stopped_X.find(X[j].id) != stopped_X.end()) {
                continue;
            }
            if (Y[i].x > X[j].x && Y[i].y < X[j].y) {
                if (Y[i].x - X[j].x < X[j].y - Y[i].y) {
                    ans[X[j].id].insert(Y[i].id);
                    ans_int[X[j].id] += ans_int[Y[i].id] + 1;
                    break;
                }
                else if (Y[i].x - X[j].x > X[j].y - Y[i].y){
                    ans[Y[i].id].insert(X[j].id);
                    stopped_X.insert(X[j].id);
                    ans_int[Y[i].id] += ans_int[X[j].id] + 1;
                }
            }
        }
    }

/*    for (int i = 0; i < n; i++) {
        cout << i + 1 << ": ";
        for (const auto j : ans[i]) {
            cout << j + 1 << ' ';
        }
        cout << '\n';
    }*/

    for (int i = 0; i < n; i++) {
        cout << ans_int[i] << '\n';
    }
}
