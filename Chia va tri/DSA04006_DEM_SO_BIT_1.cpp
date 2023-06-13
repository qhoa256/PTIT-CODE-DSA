#include <bits/stdc++.h>
#pragma gcc optimize("Ofast")
#define endl '\n'
using namespace std;

using ll = long long;

int check(ll i, ll n, ll cnt)
{
	if (i % 2 == 1)
		return 1;
	else
	{
		ll pos = pow(2, cnt);
		if (pos == i)
			return n % 2;
		else
		{
			if (i < pos)
				return check(i, n / 2, cnt - 1);
			else
				return check(i - pos, n / 2, cnt - 1);
		}
	}
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
	ll t;
	cin >> t;
	while (t--)
	{
		ll n, l, r;
		cin >> n >> l >> r;
		ll dem = log2(n);
		ll ans = 0;
		for (ll i = l; i <= r; i++)
		{
			if (check(i, n, dem))
			{
				ans++;
			}
		}
		cout << ans << endl;
	}
	return 0;
}