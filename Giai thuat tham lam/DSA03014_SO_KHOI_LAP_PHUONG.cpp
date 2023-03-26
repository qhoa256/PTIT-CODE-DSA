#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int t, x[105];
string s;
ll res;
map<ll, bool> mp;

bool check(ll n) {
	ll lc = (ll)pow(n, 1.0 / 3);
	return (lc * lc * lc == n || (lc + 1) * (lc + 1) * (lc + 1) == n);
}
void Try(int i) {
	for (int j = 0; j <= 1; j++) {
		x[i] = j;
		if (i == s.size() - 1) {
			ll tmp = 0;
			for (int k = 0; k < s.size(); k++) {
				if (x[k]) {
					tmp = tmp * 10 + (s[k] - '0');
				}
			}
			if (check(tmp) && tmp > res) res = tmp;
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
		res = 0;
		Try(0);
		if (res == 0) cout << -1 << endl;
		else cout << res << endl;
	}
	return 0;
}