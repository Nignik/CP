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
	setIO("outofplace");

	int n;
	cin >> n;
	vector<int> a(n);
	int id = -1;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	
	for (int i = 1; i < n-1; i++) {
		if ((a[i] < a[i-1] && a[i-1] <= a[i+1]) || (a[i] > a[i+1] && a[i-1] <= a[i+1])) {
			id = i;
		}
	}
	if (id == -1) {
		if (a[0] > a[1] && a[1] < a[2]) {
			id = 0;
		}
		else {
			id = n-1;
		}
	}

	bool up;
	if (id == 0)
	{
		up = true;
	}
	else if (id == n - 1)
	{
		up = false;
	}
	else if (a[id] > a[id + 1])
	{
		up = true;
	}
	else
	{
		up = false;
	}

	set<int> nums;
	int x = id;
	if (up)
	{
		while (id < n - 1 && a[x] > a[id + 1])
		{
			nums.insert(a[id + 1]);
			id++;
		}
	}
	else
	{
		while (id > 0 && a[x] < a[id - 1])
		{
			nums.insert(a[id - 1]);
			id--;
		}
	}

	cout << nums.size() << '\n';
}