#include <bits/stdc++.h>

using namespace std;

void setIO(string s) {
	ios_base::sync_with_stdio(0); cin.tie(0);
	if (fopen((s+".in").c_str(), "r")){
		freopen((s+".in").c_str(),"r",stdin);
		freopen((s+".out").c_str(),"w",stdout);
	}
}

int N = 8;
vector<string> permutation;
map<string, bool> chosen;
set<string> names = { "Bessie", "Buttercup", "Belinda", "Beatrice", "Bella", "Blue", "Betsy", "Sue" };
map<string, vector<string>> rules;

vector<vector<string>> answers;

void permute()
{
	if (permutation.size() == N)
	{
		for (int i = 0; i < N; i++)
		{
			if (i == 0)
			{
				if (rules[permutation[i]].size() == 2 || (rules[permutation[i]].size() > 0 && rules[permutation[i]][0] != permutation[i + 1]))
				{
					return;
				}
			}
			else if (i == N - 1)
			{
				if (rules[permutation[i]].size() == 2 || (rules[permutation[i]].size() > 0 && rules[permutation[i]][0] != permutation[i - 1]))
				{
					return;
				}
			}
			else
			{
				if (rules[permutation[i]].size() == 2)
				{
					if (rules[permutation[i]][0] != permutation[i - 1] && rules[permutation[i]][0] != permutation[i + 1])
					{
						return;
					}
					if (rules[permutation[i]][1] != permutation[i - 1] && rules[permutation[i]][1] != permutation[i + 1])
					{
						return;
					}
				}
				else if (rules[permutation[i]].size() == 1)
				{
					if (rules[permutation[i]][0] != permutation[i - 1] && rules[permutation[i]][0] != permutation[i + 1])
					{
						return;
					}
				}
			}
		}
		answers.push_back(permutation);
	}
	else
	{
		for (const auto& s : names)
		{
			if (chosen[s]) continue;
			chosen[s] = true;
			permutation.push_back(s);
			permute();
			chosen[s] = false;
			permutation.pop_back();
		}


	}
}

int main()
{
	setIO("lineup");
	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		bool second = false;
		string first;

		for (int j = 0; j < 6; j++)
		{
			string s;
			cin >> s;
			if (names.find(s) != names.end())
			{
				if (second)
				{
					rules[first].push_back(s);
					rules[s].push_back(first);
				}
				else
				{
					first = s;
					second = true;
				}
			}
		}
	}
	permute();

	for (const auto& s : answers[0])
	{
		cout << s << '\n';
	}
}