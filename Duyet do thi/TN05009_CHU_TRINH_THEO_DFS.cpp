#include <bits/stdc++.h>
#pragma gcc optimize("Ofast")
#define endl '\n'
using namespace std;

using ll = long long;

int v, e, x, y, st, fi;
bool check[2003];
int parent[2003];
vector<int> adj[2003];

void init() {
	memset(adj, 0, sizeof(adj));
	memset(parent, 0, sizeof(parent));
	memset(check, 0, sizeof(check));
	cin >> v >> e;
	for (int i = 0 ; i < e ; i++) {
		cin >> x >> y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
}

bool dfs(int u) {
	check[u] = 1;
	for (int v : adj[u]) {
		if (!check[v]) {
			parent[v] = u;
			if (dfs(v)) return 1;
		} else if (v != parent[u] && v == 1) {
			st = v; fi = u;
			return 1;
		}
	}
	return 0;
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
	int t; cin >> t;
	while (t--) {
		init();
		for (int i = 1; i <= v; i++) {
			sort(adj[i].begin(), adj[i].end());
		}
		if (dfs(1)) {
			parent[1] = 0;
			vector<int> res;
			res.push_back(st);
			while (fi != st) {
				res.push_back(fi);
				fi = parent[fi];
			}
			res.push_back(st);
			reverse(res.begin(), res.end());
			for (int x : res) cout << x << " ";
			cout << endl;
		} else cout << "NO" << endl;
	}
	return 0;
}