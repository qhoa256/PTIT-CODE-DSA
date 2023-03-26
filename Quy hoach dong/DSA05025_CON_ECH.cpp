#include <bits/stdc++.h>

using namespace std;

using ll = long long;

long dp[1005];
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
		int n;
		cin >> n;
		memset(dp, 0, sizeof(dp));
		dp[0] = 1;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= min(i, 3); j++) {
				if (i >= j) {
					dp[i] += dp[i - j];
				}
			}
		}
		cout << dp[n] << endl;
	}
	return 0;
}