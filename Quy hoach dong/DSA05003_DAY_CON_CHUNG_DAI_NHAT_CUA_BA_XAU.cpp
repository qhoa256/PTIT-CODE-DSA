#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int dp[105][105][105];
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
		int x, y, z;
		cin >> x >> y >> z;
		string x1, y1, z1;
		cin >> x1 >> y1 >> z1;
		x1 = "@" + x1;
		y1 = "@" + y1;
		z1 = "@" + z1;
		memset(dp, 0, sizeof(dp));
		for (int i = 1; i <= x; i++) {
			for (int j = 1; j <= y; j++) {
				for (int k = 1; k <= z; k++) {
					dp[i][j][k] = max({dp[i - 1][j][k], dp[i][j - 1][k], dp[i][j][k - 1]});
					if (x1[i] == y1[j] && y1[j] == z1[k]) {
						dp[i][j][k] = max(dp[i][j][k], dp[i - 1][j - 1][k - 1] + 1);
					}
				}
			}
		}
		cout << dp[x][y][z] << endl;
	}
	return 0;
}