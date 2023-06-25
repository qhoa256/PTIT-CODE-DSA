#include <bits/stdc++.h>
#pragma gcc optimize("Ofast")
#define endl '\n'
using namespace std;

using ll = long long;

ll powMod(ll a, ll b, ll m) {
	if (b == 0) return 1;
	if (b == 1) return a;
	ll res = powMod(a, b / 2, m);
	if (b % 2 == 1) return (res % m * res % m * a % m) % m;
	else return (res % m * res % m) % m;
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
		ll a, b, m;
		cin >> a >> b >> m;
		cout << powMod(a, b, m) << endl;
	}
	return 0;
}