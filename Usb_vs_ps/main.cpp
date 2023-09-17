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

    int a, b, c;
	cin >> a >> b >> c;
    int m;
    cin >> m;
    priority_queue<int, vector<int>, greater<>> usb;
    priority_queue<int, vector<int>, greater<>> ps;
    for (int i = 0; i < m; i++) {
        int x;
        string s;
        cin >> x >> s;
        if (s == "USB") {
            usb.push(x);
        }
        else {
            ps.push(x);
        }
    }

    int equipped = 0;
    ll cost = 0;
    while (a > 0 && !usb.empty()) {
        cost += usb.top();
        a--;
        equipped++;
        usb.pop();
    }
    while (b > 0 && !ps.empty()) {
        cost += ps.top();
        b--;
        equipped++;
        ps.pop();
    }
    while (c > 0 && (!usb.empty() || !ps.empty())) {
        c--;
        equipped++;

        if (!usb.empty() && !ps.empty()) {
            if (usb.top() <= ps.top()) {
                cost += usb.top();
                usb.pop();
            }
            else {
                cost += ps.top();
                ps.pop();
            }
        }
        else if (!usb.empty()) {
            cost += usb.top();
            usb.pop();
        }
        else if (!ps.empty()) {
            cost += ps.top();
            ps.pop();
        }
    }

    cout << equipped << ' ' << cost << '\n';
}
