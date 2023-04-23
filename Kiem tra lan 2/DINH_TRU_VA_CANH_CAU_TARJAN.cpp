#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int n, m;
vector<int>adj[1005];
int low[1005], disc[1005];
int cnt = 0;
int bridge = 0, articulation_point = 0;
void Tarjan(int u, int p) {
	disc[u] = low[u] = ++cnt;
	int node = (p != 0);
	for (auto &v : adj[u]) {
		if (v == p) continue;
		if (disc[v]) {
			low[u] = min(low[u], disc[v]);
		} else {
			Tarjan(v, u);
			low[u] = min(low[u], low[v]);
			if (low[v] == disc[v])
				bridge++;
			if (low[v] >= disc[u]) node++;
		}
	}
	if (node >= 2) articulation_point++;
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
	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	for (int i = 1; i <= n; i++) {
		if (!disc[i]) Tarjan(i, 0);
	}
	cout << articulation_point << " " << bridge << endl;
	return 0;
}