#include <bits/stdc++.h>
#pragma gcc optimize("Ofast")
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
		cin >> n >> m;
		set<ll> se;
		multiset<ll> se2;
		map<ll, ll> mp;
		for (ll i = 0; i < m; i++)
		{
			ll x, y;
			cin >> x >> y;
			cnt[x]++;
			cnt[y]++;
		}
		for (ll i = 1; i <= n; i++)
		{
			se.insert(cnt[i]);
			se2.insert(cnt[i]);
			mp[cnt[i]]++;
		}
		vector<ll> v(all(se));
		ll max1 = -1, max2 = -1, cnt2 = 0;
		max1 = v[v.size() - 1];
		max2 = v[v.size() - 2];
		if (se.size() >= 3)
		{
			if (mp[max1] != 1)
			{
				cout << max2 << " " << max1 - 1 << endl;
			}
			else
			{
				cout << max1 << " " << max2 - 1 << endl;
			}
		}
		else
			cout << max1 << " " << max1 - 1 << endl;
		ms(cnt);
	}
	return 0;
}