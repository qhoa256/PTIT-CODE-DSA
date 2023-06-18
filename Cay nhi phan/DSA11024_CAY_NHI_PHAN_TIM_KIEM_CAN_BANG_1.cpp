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
		ll a[n + 1] = {0};
		for (ll i = 1; i <= n; i++)
			cin >> a[i];
		sort(a, a + n + 1);
		if (n % 2 == 0)
			cout << a[n / 2] << endl;
		else
			cout << a[(n + 1) / 2] << endl;
	}
	return 0;
}