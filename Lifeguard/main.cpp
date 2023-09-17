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

struct Event {
    int t;
    int id;
    bool start;
};

bool operator<(const Event &a, const Event &b) {
    return a.t < b.t;
}

int main() {
	setIO("lifeguards");

    int n;
    cin >> n;
    vector<Event> guards;
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        guards.push_back({a, i, true});
        guards.push_back({b, i, false});
    }

    sort(guards.begin(), guards.end());
    set<int> active;
    vector<int> alone(n);
    int prev = 0;
    int total = 0;
    for (const auto& e : guards) {
        int curr = e.t;
        if (active.size() > 0) {
            total += curr - prev;
        }
        if (active.size() == 1) {
            alone[*active.begin()] += curr - prev;
        }
        if (e.start) {
            active.insert(e.id);
        }
        else {
            active.erase(e.id);
        }
        prev = curr;
    }

    int min_alone_time = *min_element(alone.begin(), alone.end());
    cout << total - min_alone_time << '\n';
}