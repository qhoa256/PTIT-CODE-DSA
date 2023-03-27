#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int dp[1005];

const int mod = (int)1e9 + 7;

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
		int n, k;
		cin >> n >> k;
		int a[n];
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		memset(dp, 0, sizeof(dp));
		dp[0] = 1;
		for (int i = 1; i <= k; i++) {
			for (int j = 0; j < n; j++) {
				if (i >= a[j]) {
					dp[i] = (dp[i] % mod) + (dp[i - a[j]] % mod);
					dp[i] %= mod;
				}
			}
		}
		cout << dp[k] << endl;
	}
	return 0;
}