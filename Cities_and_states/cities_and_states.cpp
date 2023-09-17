#include <bits/stdc++.h>
using namespace std;

int index(string s) {
	int ind = 0;
	for (char &c : s) { ind = 26 * ind + (c - 'A'); }
	return ind;
}

int main() {
	ifstream read("citystate.in");
	int N;
	read >> N;

	vector<pair<string, string>> pairs;
	for (int i = 0; i < N; i++) {
		string city;
		string state;
		read >> city >> state;
		city = city.substr(
		    0, 2);  // We only care about the first two letters of the city
		pairs.push_back({city, state});
	}

	vector<int> seen(26 * 26 * 26 * 26);
	long long total = 0;
	for (const auto &[c, s] : pairs) {
		if (c != s) { total += seen[index(s + c)]; }
		seen[index(c + s)]++;
	}

	ofstream("citystate.out") << total << endl;
}