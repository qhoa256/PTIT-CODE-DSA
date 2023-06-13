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
		sort(a, a + n);
		ll l = n / 2, r = n - 1, res = 0;
		while (r > (n / 2) && l > 0)
		{
			if (a[l] * 2 <= a[r])
			{
				r--;
				l--;
				res++;
			}
			else
			{
				l--;
				res++;
			}
		}
		if (l > 0)
		{
			res += l;
		}
		if (r > (n / 2))
			res += r - (n / 2);
		cout << res << endl;
	}
	return 0;
}