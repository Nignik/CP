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
	int n, c, p;
	cin >> t;

	while (t--) {
		cin >> n >> c >> p;

		vector<string> nouns;
		vector<string> trans;
		vector<string> intrans;
		vector<string> con;

		for (int i = 0; i < n; i++) {
			string a, b;
			cin >> a >> b;
			if (b == "noun") // 1
				nouns.push_back(a);
			else if (b == "transitive-verb") // 2
				trans.push_back(a);
			else if (b == "conjunction") // 3
				con.push_back(a);
			else						// 4	',' 5	'.' 6
				intrans.push_back(a);
		}

		int ans = 0;
		int t1, t2, combine, tack_end;
		
		for (int type_1 = 0; type_1 <= intrans.size(); type_1++) {
			int noun_cnt = (int)nouns.size(), con_cnt = (int)con.size();
			int periods = p, commas = c;
			int cur_words = 0;

			cur_words += 2 * type_1;
			noun_cnt -= type_1;
			if (noun_cnt < 0) continue;

			int type_2 = min({(int)trans.size(), noun_cnt / 2, min(con_cnt, periods) * 2 + max(0, periods - con_cnt)});
			cur_words += 3 * type_2;
			noun_cnt -= 2 * type_2;

			int total = type_1 + type_2;
			int connections = type_1 + type_2 - 1;
			int can_combine = min((connections + 1) / 2, con_cnt);
			cur_words += can_combine;
			periods -= total - can_combine;
			if (periods < 0) continue;

			int tack = 0;
			if (type_2 > 0) {
				tack = min(noun_cnt, commas);
				cur_words += tack;
			}
			if (cur_words > ans) {
				ans = cur_words;
				t1 = type_1;
				t2 = type_2;
				combine = can_combine;
				tack_end = tack;
			}
		}
		cout << ans << '\n';

		if (ans == 0) {
			cout << '\n';
			continue;
		}

		vector<vector<string>> sentences;

		for (int i = 0; i < t1; i++) {
			sentences.push_back({nouns.back(), intrans.back()});
			nouns.pop_back();
			intrans.pop_back();
		}

		for (int i = 0; i < t2; i++) {
			sentences.push_back({nouns.back(), trans.back()});
			nouns.pop_back();
			trans.pop_back();
			sentences.back().push_back(nouns.back());
			nouns.pop_back();
		}

		string output;
		for (int i = 0; i < sentences.size(); i++) {
			for (string j : sentences[i]) { output += j + " ";}
			if (i % 2 == 0 && combine) {
				combine--;

				output += con.back() + " ";
				con.pop_back();
			}
			else {
				output.pop_back();
				output += ". ";
			}
		}

		output.pop_back();
		if (tack_end > 0) {
			output.pop_back();
			for (int i = 0; i < tack_end; i++) {
				output += ", " + nouns.back();
				nouns.pop_back();
			}
			output += ".";
		}
		cout << output  << '\n';
	}

	
}