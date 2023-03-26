#include <bits/stdc++.h>

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
	while (t--) {
		int n, v;
		cin >> n >> v;
		int w[n + 1], c[n + 1];
		for (int i = 1; i <= n; i++) {
			cin >> w[i];
		}
		for (int i = 1; i <= n; i++) {
			cin >> c[i];
		}
		int dp[1005][1005];
		memset(dp, 0, sizeof(dp));
		for (int i = 1; i <= n; i++) {
			for (int j = 0; j <= v; j++) {
				dp[i][j] = dp[i - 1][j];
				if (j >= w[i]) {
					dp[i][j] = max(dp[i][j], dp[i - 1][j - w[i]] + c[i]);
				}
			}
		}
		cout << dp[n][v] << endl;
	}
	return 0;
}