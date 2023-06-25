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
		ll n, s, sum = 0, ok = 0;
		cin >> n >> s;
		ll a[n];
		for (auto &x : a)
		{
			cin >> x;
			if (x == 0)
				ok = 1;
		}
		map<ll, bool> mp;
		mp[0] = true;
		for (ll i = 0; i < n; i++)
		{
			sum += a[i];
			if (mp[sum - s])
				mp[s] = true;
			mp[sum] = true;
		}
		if (s == 0)
		{
			if (ok == 0)
				cout << "NO" << endl;
			else
			{
				if (mp[s])
					cout << "YES" << endl;
				else
					cout << "NO" << endl;
			}
		}
		else
		{
			if (mp[s])
				cout << "YES" << endl;
			else
				cout << "NO" << endl;
		}
	}
	return 0;
}