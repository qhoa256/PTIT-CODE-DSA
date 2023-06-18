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
		ll Max[n], Min[n], a[n];
		for (ll i = 0; i < n; i++)
			cin >> a[i];
		Max[0] = a[0], Min[n - 1] = a[n - 1];
		for (ll i = 1; i < n; i++)
			Max[i] = max(a[i], Max[i - 1]);
		for (ll i = n - 2; i >= 0; i--)
			Min[i] = min(a[i], Min[i + 1]);
		vector<ll> ans;
		for (ll i = 0; i < n - 1; i++)
		{
			if (Max[i] <= Min[i + 1])
				ans.push_back(i);
		}
		if (ans.size())
		{
			cout << ans.size() << endl;
			for (auto &x : ans)
				cout << x + 1 << " ";
			cout << endl;
		}
		else
			cout << 0 << endl;
	}
	return 0;
}