#include <bits/stdc++.h>
#pragma gcc optimize("Ofast")
#define endl '\n'
using namespace std;

using ll = long long;
vector<int>adj[1005];
int ans = -1e9;
int visited[1005][1005];
int t, n, m;
void Try(int u, int cnt) {
	ans = max(ans, cnt);
	for (auto &x : adj[u]) {
		if (!visited[u][x]) {
			visited[u][x] = visited[x][u] = 1;
			Try(x, cnt + 1);
			visited[u][x] = visited[x][u] = 0;
		}
	}
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
		for (int i = 0; i < m; i++) {
			int x, y;
			cin >> x >> y;
			adj[x].push_back(y);
			adj[y].push_back(x);
		}
		ans = -1e9;
		for (int i = 0; i < n; i++) {
			Try(i, 0);
		}
		cout << ans << endl;
		for (int i = 0; i < n; i++) {
			adj[i].clear();
		}
		memset(visited, 0, sizeof(visited));
	}
	return 0;
}