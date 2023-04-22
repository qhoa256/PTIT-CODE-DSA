#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int t, n, m;
int parent[1005];
int sz[1005];

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
		int ok = 0;
		for (int i = 0; i < m; i++) {
			int x, y;
			cin >> x >> y;
			if (!Union(x, y)) ok = 1;
		}
		if (ok) cout << "YES\n";
		else cout << "NO\n";
	}
	return 0;
}