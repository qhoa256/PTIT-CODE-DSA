#include <bits/stdc++.h>
#pragma gcc optimize("Ofast")
#define endl '\n'
using namespace std;

using ll = long long;

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	ll t;
	cin >> t;
	while (t--)
	{
		ll n, k;
		cin >> n >> k;
		ll a[n];
		for (auto &x : a)
			cin >> x;
		ll f[n][k];
		memset(f, 0, sizeof(f));
		for (ll i = 0; i < n; i++)
		{
			for (ll j = 0; j < k; j++)
				f[i][j] = -1e9;
		}
		f[0][a[0] % k] = 1;
		for (ll i = 1; i < n; i++)
		{
			for (ll j = 0; j < k; j++)
			{
				f[i][j] = max(f[i - 1][j], f[i - 1][(j - (a[i] % k) + k) % k] + 1);
			}
		}
		cout << f[n - 1][0] << endl;
	}
	return 0;
}