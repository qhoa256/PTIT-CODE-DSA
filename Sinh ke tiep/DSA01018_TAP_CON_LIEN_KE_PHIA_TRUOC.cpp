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
	int t;
	cin >> t;
	while (t--)
	{
		int n, k;
		cin >> n >> k;
		int a[n + 1] = {0};
		for (ll i = 1; i <= k; i++) cin >> a[i];
		int i = k;
		while (a[i] == a[i - 1] + 1 && i >= 1)
		{
			i--;
		}
		if (i == 0)
		{
			for (int j = 1; j <= k; j++)
			{
				cout << n - k + j << " ";
			}
			cout << endl;
		}
		else
		{
			a[i]--;
			for (int j = i + 1; j <= k; j++)
			{
				a[j] = n - k + j;
			}
			for (int j = 1; j <= k; j++) cout << a[j] << " ";
			cout << endl;
		}
	}
	return 0;
}