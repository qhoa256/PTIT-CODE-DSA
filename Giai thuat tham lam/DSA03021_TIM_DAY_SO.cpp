#include <bits/stdc++.h>
#pragma gcc optimize("Ofast")
#define endl '\n'
using namespace std;

using ll = long long;

bool check(ll pos, ll a[], ll n)
{
	for (ll i = 0; i < n; i++)
	{
		if (a[i] / pos == a[i] / (pos + 1))
			return 0;
	}
	return 1;
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
	ll n;
	cin >> n;
	ll a[n], b[n];
	for (ll i = 0; i < n; i++)
	{
		cin >> a[i];
		b[i] = a[i];
	}
	sort(b, b + n);
	ll res = 0;
	for (ll i = b[0]; i >= 0; i--)
	{
		if (check(i, a, n))
		{
			for (ll j = 0; j < n; j++)
			{
				res += a[j] / (i + 1) + 1;
			}
			break;
		}
	}
	cout << res << endl;
	return 0;
}