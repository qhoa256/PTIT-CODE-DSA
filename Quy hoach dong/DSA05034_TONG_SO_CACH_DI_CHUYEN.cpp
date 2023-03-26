#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const int mod = 1e9 + 7;

ll dp[1000005];

ll Count(ll n, ll k) {
	memset(dp, 0, sizeof(dp));
	dp[0] = 1;
	for (ll i = 1; i <= n; i++) {
		for (ll j = 1; j <= min(i, k); j++) {
			if (i >= j) {
				dp[i] = (dp[i] % mod) + (dp[i - j] % mod);
				dp[i] %= mod;
			}
		}
	}
	return dp[n];
}
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
		ll n, k;
		cin >> n >> k;
		cout << Count(n, k) << endl;
	}
	return 0;
}