#include <bits/stdc++.h>

using namespace std;

void setIO(string s) {
	ios_base::sync_with_stdio(0); cin.tie(0);
	if (fopen((s+".in").c_str(), "r")){
		freopen((s+".in").c_str(),"r",stdin);
		freopen((s+".out").c_str(),"w",stdout);
	}
}

int main() {
	setIO("reduce");

	int n;
	cin >> n;
	vector<pair<int, int>> x(n);
	vector<pair<int, int>> y(n);
	for (int i = 0; i < n; i++) {
		cin >> x[i].first >> x[i].second;
		y[i].first = x[i].second;
		y[i].second = x[i].first;
	}
	sort(x.begin(), x.end());
	sort(y.begin(), y.end());

	long long area = INT_MAX;

	for (int i = 0; i <= 3; i++) {
		for (int j = 0; j <= 3 - i; j++) {
			for (int k = 0; k <= 3 - i - j; k++) {
				for (int u = 0; u <= 3 - i - j - k; u++) {
					set<pair<int, int>> del;

					for (int xd = 0; xd < i; xd++) {
						del.insert(x[xd]);
					}
					for (int xd = 0; xd < j; xd++) {
						del.insert(x[n-1-xd]);
					}


					int t_k = 0, t_u = 0;
					while (del.find(make_pair(y[t_k].second, y[t_k].first)) != del.end()) {
						t_k++;
					}
					while (del.find(make_pair(y[n-1-t_u].second, y[n-1-t_u].first)) != del.end()) {
						t_u++;
					}
					t_k += k;
					t_u += u;

					long long curr_area = (x[i].first - x[n - 1 - j].first) * (y[t_k].first - y[n - 1 - t_u].first);

					area = min(area, curr_area);
				}
			}
		}
	}

	cout << area << '\n';
}