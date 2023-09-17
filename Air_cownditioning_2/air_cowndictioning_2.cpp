#include <bits/stdc++.h>

using namespace std;

void setIO(string s) {
	ios_base::sync_with_stdio(0); cin.tie(0);
	if (fopen((s+".in").c_str(), "r")){
		freopen((s+".in").c_str(),"r",stdin);
		freopen((s+".out").c_str(),"w",stdout);
	}
}

int n, m;
vector<int> subset;
vector<pair<int, int>> range;
vector<int> cool;
vector<int> cost;
vector<int> barn(101);

int best_cost = INT_MAX;

bool cmp(vector<int>& a, vector<int>& b) {
	for (int i = 0; i < a.size(); i++) {
		if (a[i] > b[i]) {
			return false;
		}
	}
	return true;
}

void search(int k) {
	if (k == m) {
		int current_cost = 0;
		vector<int> cooling(101);
		for (auto i : subset) {
			for (int j = range[i].first; j <= range[i].second; j++) {
				cooling[j] += cool[i];
			}
			current_cost += cost[i];
		}

		if (cmp(barn, cooling)) {
			best_cost = min(best_cost, current_cost);
		}
	}
	else {
		search(k+1);
		subset.push_back(k);
		search(k+1);
		subset.pop_back();
	}
}

int main() {
	setIO("blist");

	cin >> n >> m;
	range.resize(m);
	cool.resize(m);
	cost.resize(m);

	for (int i = 0; i < n; i++) {
		int s, t, c;
		cin >> s >> t >> c;
		for (int j = s; j <= t; j++) {
			barn[j] = max(barn[j], c);
		}
	}

	for (int i = 0; i < m; i++) {
		int a, b, p, c;
		cin >> a >> b >> p >> c;
		range[i].first = a;
		range[i].second = b;
		cool[i] = p;
		cost[i] = c;
	}

	search(0);

	cout << best_cost << '\n';
}