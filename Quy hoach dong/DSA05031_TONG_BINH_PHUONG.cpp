#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int dp[1000005];

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
		for (int i = 1; i <= n; i++) {
			dp[i] = i;
		}
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= sqrt(i); j++) {
				dp[i] = min(dp[i], dp[i - j * j] + 1);
			}
		}
		cout << dp[n] << endl;
	}
	return 0;
}