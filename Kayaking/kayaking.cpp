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

	int n;
	int ans = 0;
	int sum = 0;
	cin >> n;
	vector<int> a(n*2);
	for (int i = 0; i < n*2; i++) {
		cin >> a[i];
	}

	sort(a.begin(), a.end());

	int best = INT_MAX;
	for (int i = 0; i < n*2; i++) {
		for (int j = i+1; j < n*2; j++) {
			vector<int> new_people;
			for (int k = 0; k < n*2; k++) {
				if (k != i && k != j) new_people.push_back(a[k]);
			}

			int total = 0;
			for (int k = 0; k < n*2-2; k+=2) {
				total += new_people[k+1] - new_people[k]; 
			}
			best = min(best, total);
		}
	}

	cout << best << '\n';
}