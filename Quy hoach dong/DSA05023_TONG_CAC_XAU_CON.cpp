#include <bits/stdc++.h>

using namespace std;

using ll = long long;

ll dp[100005];

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
		string s;
		cin >> s;
		s = "H" + s;
		memset(dp, 0, sizeof(dp));
		dp[1] = s[1] - '0';
		ll ans = 0;
		ans += dp[1];
		for (int i = 2; i < s.size(); i++) {
			dp[i] = dp[i - 1] * 10 + (s[i] - '0') * i;
			ans += dp[i];
		}
		cout << ans << endl;
	}
	return 0;
}