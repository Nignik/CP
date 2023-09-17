#include <algorithm>
#include <cstdio>
#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

int main() {
	freopen("outofplace.in", "r", stdin);
	int cow_num;
	std::cin >> cow_num;
	vector<int> cows(cow_num);
	for (int &c : cows) { std::cin >> c; }

	vector<int> sorted_order(cows);
	std::sort(sorted_order.begin(), sorted_order.end());

	// The number of cows that are out of place relative to the sorted order
	int bad_num = 0;
	for (int i = 0; i < cow_num; i++) {
		if (cows[i] != sorted_order[i]) { bad_num++; }
	}

	freopen("outofplace.out", "w", stdout);
	cout << bad_num - 1 << endl;
}