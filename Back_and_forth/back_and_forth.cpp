#include <bits/stdc++.h>

using namespace std;

void setIO(string s) {
	ios_base::sync_with_stdio(0); cin.tie(0);
	if (fopen((s+".in").c_str(), "r")){
		freopen((s+".in").c_str(),"r",stdin);
		freopen((s+".out").c_str(),"w",stdout);
	}
}

const int N = 10;

vector<int> one(101);
vector<int> two(101);

vector<int> permutation;
vector<int> whole_one(10);
vector<int> whole_two(10);

vector<int> numbers;

set<int> answers;

void search() {
	if (permutation.size() == 4) {
		vector<int> t_one = one;
		vector<int> t_two = two;

		int ONE = 1000;
		int TWO = 1000;
		for (int i = 0; i < 4; i++) {
			if (i % 2 == 0) {
				if (t_one[permutation[i]] == 0) {
					return;
				}
				t_one[permutation[i]]--;
				t_two[permutation[i]]++;
				ONE -= permutation[i];
				TWO += permutation[i];
			}
			else {
				if (t_two[permutation[i]] == 0) {
					return;
				}
				t_two[permutation[i]]--;
				t_one[permutation[i]]++;
				TWO -= permutation[i];
				ONE += permutation[i];
			}
		}

		answers.insert(ONE);
	}
	else {
		for (int i = 0; i < numbers.size(); i++) {
			permutation.push_back(numbers[i]);
			search();
			permutation.pop_back();
		}
	}
}

int main() {
	setIO("backforth");

	set<int> temp;

	for (int i = 0; i < N; i++) {
		int x;
		cin >> x;
		one[x] += 1;
		whole_one[i] = x;
		temp.insert(x);
	}
	for (int i = 0; i < N; i++) {
		int x;
		cin >> x;
		two[x] += 1;
		whole_two[i] = x;
		temp.insert(x);
	}

	for (auto i : temp) {
		numbers.push_back(i);
	}

	search();

	cout << answers.size() << '\n';
}