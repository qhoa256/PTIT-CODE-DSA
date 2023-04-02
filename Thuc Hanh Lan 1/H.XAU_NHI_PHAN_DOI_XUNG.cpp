#include <bits/stdc++.h>

using namespace std;

using ll = long long;

string s;
int dp[5005][5005];
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> s;
	for (int i = s.size() - 1; i >= 0; i--) {
		for (int j = i; j < s.size(); j++) {
			if (i == j) dp[i][j] = 1;
			else if (s[i] == s[j]) {
				if (j - i == 1) dp[i][j] = 1;
				else dp[i][j] = dp[i + 1][j - 1];
			}
		}
	}
	int q;
	cin >> q;
	while (q--) {
		int l, r;
		cin >> l >> r;
		if (dp[l - 1][r - 1]) cout << "YES\n";
		else cout << "NO\n";
	}
	return 0;
}