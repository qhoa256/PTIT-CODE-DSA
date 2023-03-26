#include <bits/stdc++.h>

using namespace std;

using ll = long long;

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
		s = ' ' + s;
		int dp[10005];
		memset(dp, 0, sizeof(dp));
		dp[0] = dp[1] = 1;
		if (s[1] == '0') {
			cout << "0\n";
			continue;
		}
		for (int i = 2; i < s.size(); i++) {
			if (s[i] == '0') {
				if (s[i - 1] > '2') {
					dp[s.size() - 1] = 0;
					break;
				}
				dp[i] = 0;
			} else {
				dp[i] = dp[i - 1];
				if ((s[i - 2] == '1' || s[i - 2] == '2') && s[i - 1] <= '6') {
					dp[i] += dp[i - 2];
				}
			}
		}
		cout << dp[s.size() - 1] << endl;
	}
	return 0;
}