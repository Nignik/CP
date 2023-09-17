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
	setIO("swap");

	int n, k;
	cin >> n >> k;
	int a1, a2, b1, b2;
	cin >> a1 >> a2 >> b1 >> b2;

	vector<int> c(n + 1);
	for (int i = 1; i <= n; i++) {
		c[i] = i;
	}

	vector<int> model = c;
	vector<vector<int>> permutations;
	int loop;

	permutations.push_back(c);
	for (int i = 0; i < k; i++) {
		reverse(c.begin() + a1, c.begin() + a2 + 1);
		reverse(c.begin() + b1, c.begin() + b2 + 1);
		

		/*for (int j = 1; j <= n; j++) {
			cout << c[j] << ' ';
		}
		cout << '\n';*/


		if (c == model) {
			loop = i + 1;
			int final_id = k % loop;
			for (int j = 1; j <= n; j++) {
				cout << permutations[final_id][j] << '\n';
			}
			return 0;
		}
		permutations.push_back(c);
	}

	for (int j = 1; j <= n; j++) {
		cout << c[j] << '\n';
	}
}