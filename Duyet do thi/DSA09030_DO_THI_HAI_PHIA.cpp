#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int t, n, m;
vector<int>adj[1005];

int color[1005];
bool DFS(int u, int par) {
	color[u] = 3 - color[par];
	for (auto x : adj[u]) {
		if (color[x] == 0) {
			if (!DFS(x, u)) return false;
		} else if (color[u] == color[x]) {
			return false;
		}
	}
	return true;
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
		color[0] = 1;
		bool check = true;
		for (int i = 1; i <= n; i++) {
			if (color[i] == 0) {
				if (!DFS(i, 0)) {
					check = false;
				}
			}
		}
		if (check) cout << "YES\n";
		else cout << "NO\n";
		for (int i = 1; i <= n; i++) {
			adj[i].clear();
		}
		memset(color, 0, sizeof(color));
	}
	return 0;
}