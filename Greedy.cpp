#include <bits/stdc++.h>
#pragma gcc optimize("Ofast")
#define endl '\n'
using namespace std;

using ll = long long;

bool check(ll n) {
	ll x = (ll)pow(n, 1.0 / 3);
	return x * x * x == n || (x + 1) * (x + 1) * (x + 1) == n;
}

int t, n, a[1005];
ll res;
string s;
void Try(int i) {
	for (int j = 0; j <= 1; j++) {
		a[i] = j;
		if (i == n) {
			ll tmp = 0;
			for (int k = 1; k <= n; k++) {
				if (a[k]) {
					tmp = tmp * 10 + (s[k] - '0');
				}
			}
			if (check(tmp) && tmp > res) {
				res = tmp;
			}
		} else Try(i + 1);
	}
}
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> t;
	while (t--) {
		cin >> s;
		s = "@" + s;
		n = s.size() - 1;
		res = 0;
		Try(1);
		if (res != 0) cout << res;
		else cout << -1;
		cout << endl;
	}
	return 0;
}