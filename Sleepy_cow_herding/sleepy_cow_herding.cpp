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
	setIO("herding");

	int a, b, c;
	vector<int> x(3);
	cin >> x[0] >> x[1] >> x[2];
	sort(x.begin(), x.end());
	a = x[0];
	b = x[1];
	c = x[2];

	int min_moves;
	if (a == b-2 || b == c-2) {
		min_moves = 1;
	}
	else if(a == b-1 && b == c-1)
		{
			min_moves = 0;
		}
	else {
		min_moves = 2;
	}
	
	int cnt = 0;
	while(a != b-1 || b != c-1) {
		if (b - a > c - b) {
			c = a+1;
			swap(b, c);
		}
		else {
			a = c-1;
			swap(a, b);
		}
		cnt++;
	}



	cout << min_moves << '\n' << cnt << '\n';

}