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
		int a[n + 1];
		for (int i = 1; i <= n; i++) {
			cin >> a[i];
		}
		memset(dp, 0, sizeof(dp));
		for (int i = 1; i <= n; i++) {
			dp[i] = a[i];
			for (int j = 1; j <= i; j++) {
				if (a[i] > a[j]) {
					dp[i] = max(dp[i], dp[j] + a[i]);
				}
			}
		}
		cout << *max_element(dp + 1, dp + n + 1) << endl;
	}
	return 0;
}