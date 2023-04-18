#include <bits/stdc++.h>

using namespace std;

using ll = long long;
typedef pair<int, pair<int, int>> iii;
int a[1005][1005], d[1005][1005];
int t, n, m;
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, -1, 1};
void dijkstra(int i, int j) {
	priority_queue<iii, vector<iii>, greater<iii>>q;
	d[i][j] = a[i][j];
	q.push({d[i][j], {i, j}});
	while (!q.empty()) {
		auto top = q.top();
		q.pop();
		int i = top.second.first, j = top.second.second, dij = top.first;
		if (dij > d[i][j]) continue;
		for (int k = 0; k < 4; k++) {
			int i1 = i + dx[k], j1 = j + dy[k];
			if (i1 >= 1 && i1 <= n && j1 >= 1 && j1 <= m) {
				if (d[i1][j1] > d[i][j] + a[i1][j1]) {
					d[i1][j1] = d[i][j] + a[i1][j1];
					q.push({d[i1][j1], {i1, j1}});
				}
			}
		}
	}
	cout << d[n][m] << endl;
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
				d[i][j] = 1e9;
			}
		}
		dijkstra(1, 1);
	}
	return 0;
}