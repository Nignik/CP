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
	setIO("notlast");

	int n;
	cin >> n;
	map<string, int> m;
	m["Bessie"] = 0;
	m["Elsie"] = 0;
	m["Daisy"] = 0;
	m["Gertie"] = 0;
	m["Annabelle"] = 0;
	m["Maggie"] = 0;
	m["Henrietta"] = 0;

	for (int i = 0; i < n; i++)
	{
		string name;
		int milk;
		cin >> name >> milk;
		m[name] += milk;
	}

	pair<string, int> last;
	pair<string, int> notlast;
	last = make_pair("none", INT_MAX);
	notlast = make_pair("none", INT_MAX);

	bool last_tie = false;
	bool notlast_tie = false;

	for (const auto& [key, value] : m)
	{
		if (value < last.second)
		{
			if (last_tie)
			{
				notlast_tie = true;
			}
			notlast.first = last.first;
			notlast.second = last.second;
			last.first = key;
			last.second = value;
		}
		else if (value == last.second)
		{
			last_tie = true;
		}
		else if (value < notlast.second)
		{
			notlast.first = key;
			notlast.second = value;
			notlast_tie = false;
		}
		else if (value == notlast.second)
		{
			notlast_tie = true;
		}
	}

	if (notlast.first == "none" || notlast_tie) cout << "Tie" << '\n';
	else cout << notlast.first << '\n';
}