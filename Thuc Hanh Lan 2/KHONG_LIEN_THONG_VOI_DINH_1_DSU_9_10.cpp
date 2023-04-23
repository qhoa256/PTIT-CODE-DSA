#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int parent[1005];
int sz[1005];
int n, m;

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

void Union(int u, int v) {
	v = Find(v);
	u = Find(u);
	if (u == v) return;
	if (sz[u] < sz[v]) swap(u, v);
	sz[u] += sz[v];
	parent[v] = u;
	return;
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
	for (int i = 1; i <= m; i++) {
		int x, y;
		cin >> x >> y;
		Union(x, y);
	}
	int ok = 0;
	for (int i = 1; i <= n; i++) {
		if (parent[i] != parent[1]) {
			ok = 1;
			cout << i << endl;
		}
	}
	if (!ok) cout << 0;
	return 0;
}