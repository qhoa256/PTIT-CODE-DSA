#include <bits/stdc++.h>

using namespace std;

using ll = long long;

vector<pair<int, int>>adj[1005];
int t, n, m, s;
int d[1005];
void dijkstra(int s) {
	fill(d + 1, d + n + 1, 1e9);
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>q;
	d[s] = 0;
	q.push({d[0], s});
	while (!q.empty()) {
		int u = q.top().second;
		int du = q.top().first;
		q.pop();
		if (du > d[u]) continue;
		for (auto &p : adj[u]) {
			int v = p.first;
			int w = p.second;
			if (d[v] > d[u] + w) {
				d[v] = d[u] + w;
				q.push({d[v], v});
			}
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
		cin >> n >> m >> s;
		for (int i = 0; i < m; i++) {
			int x, y, w;
			cin >> x >> y >> w;
			adj[x].push_back({y, w});
			adj[y].push_back({x, w});
		}
		dijkstra(s);
		for (int i = 1; i <= n; i++) {
			cout << d[i] << " ";
		}
		cout << endl;
		memset(adj, 0, sizeof(adj));
	}
	return 0;
}