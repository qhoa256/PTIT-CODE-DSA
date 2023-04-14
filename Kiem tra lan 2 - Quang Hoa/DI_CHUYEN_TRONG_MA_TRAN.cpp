#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int dp[1005][1005];
int A[1005][1005];
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> A[i][j];
		}
	}
	memset(dp, 0, sizeof(dp));
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (i == 1) dp[i][j] = dp[i][j - 1] + A[i][j];
			else if (j == 1) dp[i][j] = dp[i - 1][j] + A[i][j];
			else {
				dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]) + A[i][j];
			}
		}
	}
	cout << dp[n][m] << endl;
	return 0;
}