#include <bits/stdc++.h>
#pragma gcc optimize("Ofast")
using namespace std;

using ll = long long;

int n, m;
int parent[1005];
int sz[1005];

struct Edge {
	int x, y, w;
};

vector<Edge>E;

void init() {
	for (int i = 1; i <= n; i++) {
		sz[i] = 1;
		parent[i] = i;
	}
}
int Find(int u) {
	if (u == parent[u]) return u;
	else return parent[u] = Find(parent[u]);
}

bool Union(int u, int v) {
	u = Find(u);
	v = Find(v);
	if (u == v) return false;
	if (sz[u] < sz[v]) swap(u, v);
	sz[u] += sz[v];
	parent[v] = u;
	return true;
}

void Kruskal() {
	int cost = 0, cnt = 0;
	sort(E.begin(), E.end(), [](Edge e1, Edge e2)->bool{
		return e1.w < e2.w;
	});
	for (auto &e : E) {
		if (cnt == n - 1) break;
		if (Union(e.x, e.y)) {
			cnt++;
			cost += e.w;
		}
	}
	if (cnt != n - 1) cout << "IMPOSSIBLE";
	else cout << cost;
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
	cin >> n >> m;
	init();
	for (int i = 0; i < m; i++) {
		int x, y, w;
		cin >> x >> y >> w;
		E.push_back({x, y, w});
	}
	Kruskal();
	return 0;
}