#include <bits/stdc++.h>
#pragma gcc optimize("Ofast")
#define endl '\n'
using namespace std;

using ll = long long;

int parent[1000005], sz[1000005];

int t, n;

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
	n = t;
	init();
	for (int i = 0; i < n; i++) {
		int x, y, z;
		cin >> x >> y >> z;
		if (z == 2) {
			if (Find(x) != Find(y)) cout << "0\n";
			else cout << "1\n";
		} else {
			Union(x, y);
		}
	}
	return 0;
}