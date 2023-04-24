#include <bits/stdc++.h>
#pragma gcc optimize("Ofast")
using namespace std;

using ll = long long;

int n, m;
int parent[200005];
int sz[200005];

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

void Union(int u, int v) {
	u = Find(u);
	v = Find(v);
	if (u == v) return;
	if (sz[u] < sz[v]) swap(u, v);
	sz[u] += sz[v];
	parent[v] = u;
	return;
}
int main()
{
// #ifndef ONLINE_JUDGE
// 	freopen("input.txt", "r", stdin);
// 	freopen("output.txt", "w", stdout);
// #endif
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	init();
	map<pair<ll, ll>, ll>mp;
	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		mp[ {x, y}] = mp[ {y, x}] = 1;
	}
	for (int i = 1; i <= n; i++) {
		for (int j = i + 1; j <= n; j++) {
			if (mp[ {i, j}] == 0 && mp[ {j, i}] == 0) {
				Union(i, j);
			}
		}
	}
	int cnt = 0;
	vector<int>res;
	for (int i = 1; i <= n; i++) {
		if (i == parent[i]) {
			res.push_back(sz[i]);
			cnt++;
		}
	}
	sort(res.begin(), res.end());
	cout << cnt << endl;
	for (auto &x : res) {
		cout << x << " ";
	}
	return 0;
}