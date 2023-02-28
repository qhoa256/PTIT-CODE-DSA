#include <bits/stdc++.h>

using namespace std;

using ll = long long;
const int mod = 1e9 + 7;

ll powMod(ll a, ll b) {
	if (b == 0) return 1;
	if (b == 1) return a;
	ll x = powMod(a, b / 2);
	if (b % 2 == 0) return (x % mod * x % mod) % mod;
	else return (x % mod * x % mod * a) % mod;
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
	while (1) {
		ll x, y;
		cin >> x >> y;
		if (x + y == 0) break;
		cout << powMod(x, y) << endl;
	}
	return 0;
}