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
		ll a[n], sum = 0, cnt[10] = {0};
		for (auto &x : a)
		{
			cin >> x;
			sum += x;
			cnt[x]++;
		}
		bool ok = false;
		if (sum % 3 == 1)
		{
			if (cnt[1] > 0)
				cnt[1]--, ok = true;
			else if (cnt[4] > 0)
				cnt[4]--, ok = true;
			else if (cnt[7] > 0)
				cnt[7]--, ok = true;
		}
		else if (sum % 3 == 2)
		{
			if (cnt[2] > 0)
				cnt[2]--, ok = true;
			else if (cnt[5] > 0)
				cnt[5]--, ok = true;
			else if (cnt[8] > 0)
				cnt[8]--, ok = true;
		}
		else
			ok = true;
		if (!ok)
		{
			cout << -1 << endl;
			continue;
		}
		for (ll i = 9; i >= 0; i--)
		{
			while (cnt[i]--)
				cout << i;
		}
		cout << endl;
	}
	return 0;
}