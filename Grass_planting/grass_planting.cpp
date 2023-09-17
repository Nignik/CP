#include <bits/stdc++.h>

using namespace std;

void setIO(string s) {
	ios_base::sync_with_stdio(0); cin.tie(0);
	if (fopen((s+".in").c_str(), "r")){
		freopen((s+".in").c_str(),"r",stdin);
		freopen((s+".out").c_str(),"w",stdout);
	}
}
const int N = 10e5+5;

vector<int> a[N];

bool visited[N];
int dist[N];
queue<int> q;

int main() {
	setIO("planting");

	int n;
	int ans = 0;
	cin >> n;

	for (int i = 0; i < n-1; i++) {
		int x, y;
		cin >> x >> y;
		a[x].push_back(y);
		a[y].push_back(x);
	}

	visited[1] = true;
	dist[1] = 0;
	q.push(1);

	int cnt = 0;
	while (!q.empty()) {
		int s = q.front(); q.pop();

		int temp = 0;

		for (const auto& u: a[s]) {
			if (visited[u])  {
				/*temp += a[u].size();*/
				continue;
			}
			visited[u] = true;
			dist[u] = dist[s]+1;
			q.push(u);
		}

		cnt = max(cnt, (int)a[s].size() + 1);
	}

	cout << cnt << '\n';
}