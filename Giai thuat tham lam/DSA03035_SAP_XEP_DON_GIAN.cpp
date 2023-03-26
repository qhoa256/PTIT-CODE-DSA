#include<bits/stdc++.h>

using namespace std;
#pragma GCC optimize("Ofast")
using ll = long long;

int dp[1000005];

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n; cin >> n;
	int a[n];
	int res = 0;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		dp[a[i]] = dp[a[i] - 1] + 1;
		res = max(res, dp[a[i]]);
	}
	cout << n - res;
}