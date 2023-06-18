#include <bits/stdc++.h>
#pragma gcc optimize("Ofast")
#define endl '\n'
using namespace std;

using ll = long long;

ll Max[100005], a[100005];

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
		for (ll i = 0; i < n; i++)
			cin >> a[i];
		Max[n - 1] = a[n - 1];
		for (ll i = n - 2; i >= 0; i--)
		{
			Max[i] = max(a[i], Max[i + 1]);
		}
		ll i = 0, j = 0, ans = -1;
		while (i < n && j < n)
		{
			if (Max[j] > a[i])
			{
				ans = max(ans, j - i);
				j++;
			}
			else
				i++;
		}
		cout << ans << endl;
	}
	return 0;
}