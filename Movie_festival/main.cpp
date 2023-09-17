#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void setIO(string s) {
	ios_base::sync_with_stdio(0); cin.tie(0);
	if (fopen((s+".in").c_str(), "r")){
		freopen((s+".in").c_str(),"r",stdin);
		freopen((s+".out").c_str(),"w",stdout);
	}
}

int main() {
	setIO("blist");

	int n;
    cin >> n;
    vector<pair<int, int>> movies(n);
    for (int i = 0; i < n; i++) {
        int start, end;
        cin >> start >> end;
        movies[i] = {end, start};
    }
    sort(movies.begin(), movies.end());

    int movies_cnt = 0;
    int current_end = -1;
    for (int i = 0; i < n; i++) {
        if (movies[i].second >= current_end) {
            movies_cnt++;
            current_end = movies[i].first;
        }
    }
    cout << movies_cnt << '\n';
}
