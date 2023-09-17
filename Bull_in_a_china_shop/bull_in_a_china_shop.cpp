#include <bits/stdc++.h>

using namespace std;

void setIO(string s) {
	ios_base::sync_with_stdio(0); cin.tie(0);
	if (fopen((s+".in").c_str(), "r")){
		freopen((s+".in").c_str(),"r",stdin);
		freopen((s+".out").c_str(),"w",stdout);
	}
}

struct Vec2 {
	int x, y;
};

int main() {
	setIO("blist");

	int n, k;
	cin >> n >> k;
	vector<Vec2> cow;
	set<Vec2> cow_set;
	vector<vector<Vec2>> pieces(k);

	for (int j = 0; j < n; j++) {
			string s;
			cin >> s;
			for (int x = 0; x < n; x++) {
				if (s[x] == '#') {
					cow.push_back({x, j});
					cow_set.insert({x, j});
				}
			}
		}

	for (int i = 0; i < k; i++) {
		for (int j = 0; j < n; j++) {
			string s;
			cin >> s;
			for (int x = 0; x < n; x++) {
				if (s[x] == '#') {
					pieces[k].push_back({x, j});
				}
			}
		}
	}

	map<int, vector<Vec2>> fitting;

	for (int i = 0; i < k; i++) {
		for (int x = 0; x < n; x++) {
			for (int y = 0; y < n; y++) {

				bool valid = true;
				for (auto crd : pieces[k]) {
					if (cow_set.find({crd.x + x, crd.y + y}) == cow_set.end()) {
						valid = false;
						break;
					}
				}
				if (valid) {
					fitting[i].push_back({x, y});
				}

				valid = true;
				for (auto crd : pieces[k]) {
					if (cow_set.find({crd.x - x, crd.y - y}) == cow_set.end()) {
						valid = false;
						break;
					}
				}
				if (valid) {
					fitting[i].push_back({-x, -y});
				}
			}
		}
	}

	int ans_1, ans_2;

	for (auto [key_one, value_one] : fitting) {
		for (auto [key_two, value_two] : fitting) {
			if (pieces[key_one].size() + pieces[key_two].size() == cow_set.size()) {
				bool valid = true;
				set<Vec2> temp_set;

				for (auto piece : pieces[key_one]) {
					temp_set.insert(piece);
					if (cow_set.find(piece) == cow_set.end()) {
						valid = false;
					}
				}
				for (auto piece : pieces[key_two]) {
					if (cow_set.find(piece) == cow_set.end() || temp_set.find(piece) != temp_set.end()) {
						valid = false;
						break;
					}
				}

				if (valid) {
					ans_1 = key_one;
					ans_2 = key_two;
				}
			}
		}
	}

	cout << ans_1 << ans_2 << '\n';
}