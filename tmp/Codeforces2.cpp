#include <bits/stdc++.h>
#pragma gcc optimize("Ofast")
#define endl '\n'
using namespace std;

using ll = long long;

int t, n, a[1005];

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> t;
	while (t--)
	{
		cin >> n;
		int c = 0, l = 0, Min = 1e9;
		int a[n];
		for (int i = 0; i < n; i++) {
			cin >> a[i];
			if (a[i] % 2 == 1) l++;
			else c++;
			Min = min(Min, a[i]);
		}
		if (c == 0 || l == 0)
			cout << "YES\n";
		else
		{
			if (Min % 2 == 0)
			{
				if (l != 0)
					cout << "NO\n";
				else
					cout << "YES\n";
			}
			else
				cout << "YES\n";
		}
	}
	return 0;
}