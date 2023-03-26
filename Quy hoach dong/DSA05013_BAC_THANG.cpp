#include<bits/stdc++.h>
using namespace std;

using ll = long long;

const int mod = (int)1e9 + 7;

ll countWays(ll n, ll k) {
	ll dp[n + 1];
	memset(dp, 0, sizeof(dp));
	dp[0] = 1;
	for (ll i = 1; i <= n; i++) {
		for (ll j = 1; j <= k; j++) {
			if (i - j >= 0) {
				dp[i] += dp[i - j];
				dp[i] %= mod;
			}
		}
	}
	return dp[n];
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int t;
	cin >> t;
	while (t--) {
		ll n, k;
		cin >> n >> k;
		cout << countWays(n, k) << endl;
	}
	return 0;
}
