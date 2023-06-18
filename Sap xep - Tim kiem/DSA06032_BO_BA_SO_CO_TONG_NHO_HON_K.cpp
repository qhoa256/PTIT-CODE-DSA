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
		for (auto &x : a) cin >> x;
		ll cnt = 0;
		sort(a, a + n);
		for (ll i = 0; i < n; i++)
		{
			if (a[i] > k) break;
			for (ll j = i + 1; j < n; j++)
			{
				ll idex = upper_bound(a + j + 1, a + n, k - a[i] - a[j] - 1) - a;
				if (idex > j) cnt += idex - j - 1;
				else break;
			}
		}
		cout << cnt << endl;
	}
	return 0;
}