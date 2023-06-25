#include <bits/stdc++.h>
#pragma gcc optimize("Ofast")
#define endl '\n'
using namespace std;

using ll = long long;

int mod = 1e9 + 7;

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
		long long dp[n + 1][k + 1];
		memset(dp, 0, sizeof(dp));
		for (int i = 1; i <= 9; i++)
			dp[1][i] = 1;

		for (int i = 2; i <= n; i++)
			for (int l = 0; l <= 9; l++)
				for (int j = l; j <= k; j++)
					dp[i][j] = (dp[i][j] % mod + dp[i - 1][j - l] % mod) % mod;

		cout << dp[n][k] << endl;
	}
	return 0;
}