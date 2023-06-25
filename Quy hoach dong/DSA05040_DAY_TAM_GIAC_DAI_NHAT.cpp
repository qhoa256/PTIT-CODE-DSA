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
	int t;
	cin >> t;
	while (t--)
	{
		ll n;
		cin >> n;
		ll dem1[n], dem2[n];
		ll a[n];
		for (auto &x : a)
			cin >> x;
		fill(dem1, dem1 + n, 1);
		fill(dem2, dem2 + n, 1);
		for (ll i = 1; i < n; i++)
		{
			if (a[i] > a[i - 1])
				dem1[i] = dem1[i - 1] + 1;
		}
		for (ll i = n - 2; i >= 0; i--)
		{
			if (a[i] > a[i + 1])
				dem2[i] = dem2[i + 1] + 1;
		}
		ll ans = -1;
		for (ll i = 0; i < n; i++)
		{
			ans = max(ans, dem1[i] + dem2[i] - 1);
		}
		cout << ans << endl;
	}
	return 0;
}