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
		for (auto &x : a) cin >> x;
		ll cnt = 1, pos;
		vector<string> v;
		for (ll i = 0; i < n - 1; i++)
		{
			ll ok = 0;
			for (ll j = 0; j < n - i - 1; j++)
			{
				if (a[j] > a[j + 1])
				{
					ok = 1;
					swap(a[j], a[j + 1]);
				}
			}
			if (ok == 0) break;
			string res = "";
			res = "Buoc " + to_string(cnt++) + ": ";
			for (ll j = 0; j < n; j++)
			{
				res += to_string(a[j]) + " ";
			}
			v.push_back(res);
		}
		reverse(v.begin(), v.end());
		for (auto x : v) cout << x << endl;
	}
	return 0;
}