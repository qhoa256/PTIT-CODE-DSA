#include <bits/stdc++.h>

using namespace std;

using ll = long long;

struct Edge {
	int x, y, w;
};

int t, n, m;
int parent[1005];
int sz[1005];
vector<Edge>E;
void init() {
	for (int i = 1; i <= n; i++) {
		parent[i] = i;
		sz[i] = 1;
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
	vector<Edge>mst;
	sort(E.begin(), E.end(), [](Edge a, Edge b)->bool{
		return a.w < b.w;
	});
	int d = 0;
	for (auto e : E) {
		if (mst.size() == n - 1) break;
		if (Union(e.x, e.y)) {
			mst.push_back(e);
			d += e.w;
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
		init();
		for (int i = 0; i < m; i++) {
			int x, y, w;
			cin >> x >> y >> w;
			E.push_back({x, y, w});
		}
		Kruskal();
		memset(parent, 0, sizeof(parent));
		memset(sz, 0, sizeof(sz));
		E.clear();
	}
	return 0;
}