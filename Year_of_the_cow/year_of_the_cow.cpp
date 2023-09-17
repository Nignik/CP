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

	map<string, int> cal;
	cal["Ox"] = 1;
	cal["Tiger"] = 2;
	cal["Rabbit"] = 3;
	cal["Dragon"] = 4;
	cal["Snake"] = 5;
	cal["Horse"] = 6;
	cal["Goat"] = 7;
	cal["Monkey"] = 8;
	cal["Rooster"] = 9;
	cal["Dog"] = 10;
	cal["Pig"] = 11;
	cal["Rat"] = 12;

	int n;
	cin >> n;

	map<string, pair<string, int>> m;

	for (int i = 0; i < n; i++)
	{
		string one;
		string two;
		bool sign;
		int time;
		for (int j = 0; j < 8; j++)
		{
			string s;
			cin >> s;
			if (j == 0)
			{
				one = s;
			}
			else if (j == 3)
			{
				if (s == "previous")
				{
					sign = false;
				}
				else
				{
					sign = true;
				}
			}
			else if (j == 4)
			{
				if (sign)
				{
					time = cal[s];
				}
				else
				{
					time = -cal[s];
				}
			}
			else if (j == 7)
			{
				two = s;
			}
		}

		m[one] = make_pair(two, time);
	}

	int year = 0;
	string s = "Elsie";
	m["Bessie"] = make_pair("none", 1);
	while (s != "Bessie")
	{
		if (m[s].second < 0)
		{
			if (abs(m[m[s].first].second) > abs(m[s].second)) {
				year -= abs(m[m[s].first].second) - abs(m[s].second);
			}
			else if (abs(m[m[s].first].second) == abs(m[s].second)) {
				year -= 12;
			}
			else {
				year -= 12  - abs(m[s].second) + abs(m[m[s].first].second);
			}
			
		}
		else
		{
			if (abs(m[m[s].first].second) < abs(m[s].second))  {
				year += abs(m[s].second) - abs(m[m[s].first].second);
			}
			else if (abs(m[m[s].first].second) == abs(m[s].second)) {
				year += 12;
			}
			else {
				year += 12 - abs(m[m[s].first].second) + abs(m[s].second);
			}
			
		}

		s = m[s].first;
	}

	cout << abs(year) << '\n';
}