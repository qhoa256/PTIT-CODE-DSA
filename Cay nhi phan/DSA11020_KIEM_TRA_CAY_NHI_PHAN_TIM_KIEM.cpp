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
		ll n;
		cin >> n;
		ll a[n];
		for (auto &x : a)
			cin >> x;
		ll ok = 0;
		for (ll i = 1; i < n; i++)
		{
			if (a[i] <= a[i - 1])
			{
				ok = 1;
				break;
			}
		}
		if (ok == 1)
			cout << 0 << endl;
		else
			cout << 1 << endl;
	}
	return 0;
}