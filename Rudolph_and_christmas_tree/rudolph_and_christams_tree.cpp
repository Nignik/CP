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
	setIO("blist");

	int t;
	cin >> t;
	while (t--) 
	{
		double ans = 0;

		double n, d, h;
		cin >> n >> d >> h;

		double area = (d * h) / 2;

		vector<double> y(n);
		for (int i = 0; i < n; i++) {
			cin >> y[i];
		}

		ans += area;
		for (int i = 1; i < n; i++) {
			ans += area;
			double intersection = h - (y[i] - y[i-1]);
			if (intersection > 0) {
				double k = (intersection / h) * (intersection / h);
				ans -= area * k;
			}
		}

		cout << fixed << setprecision(6) << ans << '\n';
	}
}