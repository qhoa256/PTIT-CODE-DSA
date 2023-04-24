#include <bits/stdc++.h>
#pragma gcc optimize("Ofast")
using namespace std;

using ll = long long;

int t, n, m, a[1005][1005], dp[1005][1005];
void BFS(int i, int j) {
	queue<pair<int, int>>q;
	q.push({i, j});
	dp[1][1] = 0;
	while (!q.empty()) {
		auto top = q.front();
		q.pop();
		int u = top.first, v = top.second;
		if (u == n && v == m) return;
		if (dp[u][v + a[u][v]] == 1e9 && v + a[u][v] <= m) {
			dp[u][v + a[u][v]] = min(dp[u][v + a[u][v]], dp[u][v] + 1);
			q.push({u, v + a[u][v]});
		}
		if (dp[u + a[u][v]][v] == 1e9 && u + a[u][v] <= n) {
			dp[u + a[u][v]][v] = min(dp[u + a[u][v]][v], dp[u][v] + 1);
			q.push({u + a[u][v], v});
		}
	}
	return;
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
	cin >> t;
	while (t--) {
		cin >> n >> m;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				cin >> a[i][j];
			}
		}
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				dp[i][j] = 1e9;
			}
		}
		BFS(1, 1);
		if (dp[n][m] != 1e9) {
			cout << dp[n][m] << endl;
		} else {
			cout << -1 << endl;
		}
	}
	return 0;
}