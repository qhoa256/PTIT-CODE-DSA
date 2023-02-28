#include <bits/stdc++.h>

using namespace std;

using ll = long long;
const int mod = 1e9 + 7;
ll powMod(ll n, ll k) {
	if (k == 0) return 1;
	if (k == 1) return n;
	ll x = powMod(n, k / 2);
	if (k % 2 == 0) return (x % mod * x % mod) % mod;
	else return (x % mod * x % mod * n) % mod;
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
	int t;
	cin >> t;
	while (t--) {
		ll n, k;
		cin >> n >> k;
		cout << powMod(n, k) << endl;
	}
	return 0;
}