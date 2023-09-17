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
	set<int> xs;
	set<int> ys;
	vector<pair<int, int>> a(n);
	for (int i = 0; i < n; i++) {
		int x, y;
		cin >> x >> y;
		a[i] = {x, y};
		xs.insert(x);
		ys.insert(y);
	}

	sort(a.begin(), a.end());
	map<int, int> mx;
	for (int i = 0; i < n; i++) {
		mx[a[i].first] = i;
	}

	auto cmp = [&](const pair<int, int> &c1, const pair<int, int> &c2) {
		return c1.second < c2.second;
	};

	sort(a.begin(), a.end(), cmp);
	map<int, int> my;
	for (int i = 0; i < n; i++) {
		my[a[i].second] = i;
	}

	for (auto &[x, y] : a) {
		x = mx[x];
		y = my[y];
	}

	sort(a.begin(), a.end());

	vector<vector<int>> ly(n, vector<int>(n+1));
	vector<vector<int>> gy(n, vector<int>(n+1));
	for (int i = 0; i < n; i++) {
		int cy = a[i].second;
		for (int x = 1; x <= n; x++) {
			ly[cy][x] = (ly[cy][x-1] + (a[x-1].second < cy));
			gy[cy][x] = (gy[cy][x-1] + (a[x-1].second > cy));
		}
	}

	ll total = 0;
	for (int i = 0; i < n; i++) {
		for (int j = i+1; j < n; j++) {
			int bot = min(a[i].second, a[j].second);
			int top = max(a[i].second, a[j].second);

			int bot_t = 1 + ly[bot][j+1] - ly[bot][i];
			int top_t = 1 + gy[top][j+1] - gy[top][i];
			total += (ll)bot_t * top_t;
		}
	}

	total += n+1;
	cout << total << '\n';
}