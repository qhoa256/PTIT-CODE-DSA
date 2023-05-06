#include <bits/stdc++.h>

using namespace std;

using ll = long long;

vector<int>adj[1005];
bool visited[1005];

void DFS(int u) {
	visited[u] = true;
	for (auto &x : adj[u]) {
		if (!visited[x]) {
			DFS(x);
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
	int t;
	cin >> t;
	while (t--) {
		int n, m, u, v;
		cin >> n >> m >> u >> v;
		for (int i = 0; i < m; i++) {
			int x, y;
			cin >> x >> y;
			adj[x].push_back(y);
		}
		int cnt = 0;
		for (int i = 1; i <= n; i++) {
			visited[i] = true;
			DFS(u);
			if (!visited[v]) {
				cnt++;
			}
			memset(visited, false, sizeof(visited));
		}
		cout << cnt << endl;
		for (int i = 1; i <= n; i++) {
			adj[i].clear();
		}
	}
	return 0;
}