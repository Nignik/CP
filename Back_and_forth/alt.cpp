#include <bits/stdc++.h>
using namespace std;

set<int> possible;

void get_possible(int day, int a_tank, vector<int> a_buckets, int b_tank,
                  vector<int> b_buckets) {
	// Last day, add the amount of milk in the first tank.
	if (day == 4) {
		possible.insert(a_tank);
		return;
	}
	// This transfers every possible bucket from barn x to barn y.
	for (int i = 0; i < a_buckets.size(); i++) {
		// Bucket to transfer.
		int t = a_buckets[i];
		// Creates a new copy of available buckets, and transfers the ith one.
		vector<int> new_a = a_buckets;
		new_a.erase(begin(new_a) + i);
		vector<int> new_b = b_buckets;
		new_b.push_back(t);

		// Recursively call the function with the new buckets and tank amounts.
		get_possible(day + 1, b_tank + t, new_b, a_tank - t, new_a);
	}
}

int main() {
	freopen("backforth.in", "r", stdin);
	freopen("backforth.out", "w", stdout);
	vector<int> a(10);
	for (int &i : a) { cin >> i; }
	vector<int> b(10);
	for (int &i : b) { cin >> i; }

	get_possible(0, 1000, a, 1000, b);
	cout << possible.size() << endl;
}