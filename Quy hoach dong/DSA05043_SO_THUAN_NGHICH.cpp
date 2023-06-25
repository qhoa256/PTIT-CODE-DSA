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
	cin.ignore(1);
	while (t--)
	{
		string s;
		cin >> s;
		ll n = s.size(), res = 1;
		s = "@" + s;
		ll f[n + 1][n + 1];
		memset(f, 0, sizeof(f));
		for (ll i = 1; i <= n; i++)
			f[i][i] = 1;
		for (ll k = 2; k <= n; k++)
		{
			for (ll i = 1; i <= n - (k - 1); i++)
			{
				ll j = i + k - 1;
				if (s[i] == s[j])
				{
					if (k == 2)
						f[i][j] = 1;
					else
					{
						f[i][j] = f[i + 1][j - 1];
					}
				}
				if (f[i][j])
					res = max(res, j - i + 1);
			}
		}
		cout << res << endl;
	}
	return 0;
}