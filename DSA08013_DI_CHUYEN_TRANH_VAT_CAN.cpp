#include <bits/stdc++.h>
#pragma gcc optimize("Ofast")
using namespace std;

using ll = long long;

int t, n, a, b, c, d;
char A[1005][1005];
int dp[1005][1005];
int dx[4] = {0, 0, 1, -1};
int dy[4] = { -1, 1, 0, 0};

void BFS(int a, int b, int c, int d) {
	cout << a << " " << b << " " << c << " " << d << endl;
	queue<pair<int, int>>q;
	q.push({a, b});
	dp[a][b] = 0;
	while (!q.empty()) {
		auto x = q.front();
		q.pop();
		int i = x.first, j = x.second;
		cout << i << " " << j << endl;
		if (i == c && j == d) return;
		for (int k = 0; k < 4; k++) {
			int i1 = i + dx[k];
			int j1 = j + dy[k];
			if (i1 >= 1 && i1 <= n && j1 >= 1 && j1 <= n && A[i1][j1] == '.') {
				dp[i1][j1] = min(dp[i1][j1], dp[i][j] + 1);
				q.push({i1, j1});
			} else {
				break;
			}
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
		cin >> n;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				cin >> A[i][j];
				dp[i][j] = 1e9;
			}
		}
		cin >> a >> b >> c >> d;
		BFS(a + 1, b + 1, c + 1, d + 1);
		cout << dp[c + 1][d + 1] << endl;
	}
	return 0;
}