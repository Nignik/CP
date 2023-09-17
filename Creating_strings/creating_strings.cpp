#include <bits/stdc++.h>

using namespace std;

void setIO(string s) {
	ios_base::sync_with_stdio(0); cin.tie(0);
	if (fopen((s+".in").c_str(), "r")){
		freopen((s+".in").c_str(),"r",stdin);
		freopen((s+".out").c_str(),"w",stdout);
	}
}

string s;
string a = "";

set<string> answers;
vector<bool> chosen;

void permutations() {
	if (a.size() == s.size()) {
		answers.insert(a);
	}
	else {
		for (int i = 0; i < s.size(); i++) {
			if (chosen[i]) continue;
			chosen[i] = true;
			a += s[i];
			permutations();
			chosen[i] = false;
			a.pop_back();
		}
	}
}

int main() {
	setIO("blist");
	cin >> s;
	chosen.resize(s.size());

	permutations();
	cout << answers.size() << '\n';
	for (const auto& answer : answers) {
		cout << answer << '\n';
	}
}