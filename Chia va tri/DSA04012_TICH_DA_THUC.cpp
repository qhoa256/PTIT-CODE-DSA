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
		ll n, m;
		cin >> n >> m;
		ll a[n], b[m];
		for (auto &x : a)
			cin >> x;
		for (auto &x : b)
			cin >> x;
		map<ll, ll> mp;
		for (ll i = 0; i < n; i++)
		{
			for (ll j = 0; j < m; j++)
			{
				mp[i + j] += a[i] * b[j];
			}
		}
		for (auto &x : mp)
		{
			cout << x.second << " ";
		}
		cout << endl;
	}
	return 0;
}