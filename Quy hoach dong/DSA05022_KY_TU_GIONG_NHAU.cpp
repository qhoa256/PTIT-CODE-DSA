#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int dp[10005];

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
		int n, x, y, z;
		cin >> n >> x >> y >> z;
		memset(dp, 0, sizeof(dp));
		dp[1] = x;
		for (int i = 2; i <= n; i++) {
			if (i % 2 == 0) {
				dp[i] = min(dp[i - 1] + x, dp[i / 2] + z);
			} else {
				dp[i] = min({dp[i - 1] + x, dp[i / 2] + z + x, dp[i / 2 + 1] + z + y});
			}
		}
		cout << dp[n] << endl;
	}
	return 0;
}