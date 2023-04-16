#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int dx[3] = {1, 0, 1};
int dy[3] = {0, 1, 1};

int t, n, m;

int visited[1005][1005], A[1005][1005];
int dp[1005][1005];
int res = 1e9;
void BFS() {
	queue<pair<pair<int, int>, int>>q;
	q.push({{1, 1}, 0});
	visited[1][1] = 1;
	while (!q.empty()) {
		auto x = q.front();
		q.pop();
		int a = x.first.first, b = x.first.second;
		if (a == n && b == m) {
			cout << x.second << endl;
			return;
		}
		int a1, b1;
		if (a + 1 <= n)
		{
			a1 = a + abs(A[a + 1][b] - A[a][b]), b1 = b;
			if (!visited[a1][b1] && a1 <= n)
			{
				q.push({{a1, b1}, x.second + 1});
				visited[a1][b1] = 1;
			}
		}
		if (b + 1 <= m)
		{
			a1 = a; b1 = b + abs(A[a][b + 1] - A[a][b]);
			if (!visited[a1][b1] && b1 <= m)
			{
				q.push({{a1, b1}, x.second + 1});
				visited[a1][b1] = 1;
			}
		}
		if (a + 1 <= n && b + 1 <= m)
		{
			a1 = a + abs(A[a][b] - A[a + 1][b + 1]);
			b1 = b + abs(A[a][b] - A[a + 1][b + 1]);
			if (!visited[a1][b1] && (a1 <= n) && (b1 <= m))
			{
				q.push({{a1, b1}, x.second + 1});
				visited[a1][b1] = 1;
			}
		}
	}
	cout << -1 << endl;
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
				cin >> A[i][j];
			}
		}
		BFS();
		memset(visited, 0, sizeof(visited));
		memset(A, 0, sizeof(A));
	}
	return 0;
}