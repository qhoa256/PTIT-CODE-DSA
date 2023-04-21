#include <bits/stdc++.h>
#pragma gcc optimize("Ofast")
using namespace std;

using ll = long long;
int t, n, m;
vector<pair<int, int>>adj[1005];
bool v[1005];

void Prim(int s) {
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>pq;
	v[s] = true;
	int d = 0;
	for (auto &x : adj[s]) {
		if (!v[x.first]) {
			pq.push({x.second, x.first});
		}
	}
	while (!pq.empty()) {
		int u = pq.top().second;
		int w = pq.top().first;
		pq.pop();
		if (!v[u]) {
			d += w;
			v[u] = true;
			for (auto &x : adj[u]) {
				if (!v[x.first]) {
					pq.push({x.second, x.first});
				}
			}
		}
	}
	cout << d << endl;
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
			int x, y, w;
			cin >> x >> y >> w;
			adj[x].push_back({y, w});
			adj[y].push_back({x, w});
		}
		Prim(1);
		for (int i = 1; i <= n; i++) {
			adj[i].clear();
		}
		memset(v, 0, sizeof(v));
	}
	return 0;
}