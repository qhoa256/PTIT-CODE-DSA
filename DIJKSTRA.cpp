#include <bits/stdc++.h>
#pragma gcc optimize("Ofast")
using namespace std;

using ll = long long;

int t, n, m, u;
vector<pair<int, int>>adj[1005];
int d[1005];
void dijkstra(int u) {
	fill(d + 1, d + n + 1, 1e9);
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>pq;
	d[u] = 0;
	pq.push({d[0], u});
	while (!pq.empty()) {
		int u = pq.top().second;
		int du = pq.top().first;
		pq.pop();
		if (du > d[u]) continue;
		for (auto &p : adj[u]) {
			int v = p.first;
			int w = p.second;
			if (d[v] > d[u] + w) {
				d[v] = d[u] + w;
				pq.push({d[v], v});
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
	cin >> t;
	while (t--) {
		cin >> n >> m >> u;
		for (int i = 0; i < m; i++) {
			int x, y, w;
			cin >> x >> y >> w;
			adj[x].push_back({y, w});
			//adj[y].push_back({x, w});
		}
		dijkstra(u);
		for (int i = 1; i <= n; i++) {
			adj[i].clear();
			cout << u << "->" << i << " " << d[i] << " " << endl;
		}
		cout << endl;
	}
	return 0;
}