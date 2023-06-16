#include <bits/stdc++.h>
#pragma gcc optimize("Ofast")
#define endl '\n'
using namespace std;

using ll = long long;

int mod = 1e9 + 7;

ll a[10], f[101];
void init()
{
	for (ll i = 1; i <= 9; i++)
		a[i] = 1;
	f[1] = 10;
	for (ll i = 2; i <= 100; i++)
	{
		for (ll j = 1; j <= 9; j++)
		{
			ll s = 0;
			for (ll k = j; k <= 9; k++)
			{
				s += a[k];
			}
			a[j] = s;
			f[i] = ((f[i] % mod) + (s % mod)) % mod;
		}
	}
	for (ll i = 2; i <= 100; i++)
		f[i] = ((f[i] % mod) + (f[i - 1] % mod)) % mod;
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
	init();
	ll t;
	cin >> t;
	while (t--)
	{
		ll n;
		cin >> n;
		cout << f[n] << endl;
	}
	return 0;
}