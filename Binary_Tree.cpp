#include <bits/stdc++.h>
#pragma gcc optimize("Ofast")
#define endl '\n'
using namespace std;

using ll = long long;

vector<pair<int, int>>adj[1005];
int visited[1005];

void DFS(int u) {
	cout << u << " ";
	visited[u] = 1;
	for (auto &x : adj[u]) {
		if (!visited[x.first]) {
			DFS(x.first);
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
		int n, m;
		cin >> n >> m;
		for (int i = 0; i < m; i++) {
			int x, y, w;
			cin >> x >> y >> w;
			adj[x].push_back({y, w});
			adj[y].push_back({x, w});
		}
		int cnt = 1;
		for (int i = 1; i <= n; i++) {
			if (!visited[i]) {
				cout << "TPLT " << cnt << endl;
				DFS(i);
				cnt++;
				cout << endl;
			}
		}
		cout << endl;
		memset(visited, 0, sizeof(visited));
		for (int i = 1; i <= n; i++) {
			adj[i].clear();
		}
	}
	return 0;
}