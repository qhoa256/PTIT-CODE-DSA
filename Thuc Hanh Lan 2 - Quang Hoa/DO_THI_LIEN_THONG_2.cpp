#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int t, n, m;
vector<int>adj[1005];
int low[1005], disc[1005];
int cnt;
vector<pair<int, int>>res;
void Tarjan(int u, int p) {
	disc[u] = low[u] = ++cnt;
	for (auto &v : adj[u]) {
		if (v == p) continue;
		if (disc[v]) {
			low[u] = min(low[u], disc[v]);
		} else {
			Tarjan(v, u);
			low[u] = min(low[u], low[v]);
			if (low[v] == disc[v]) {
				res.push_back({min(u, v), max(u, v)});
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
		cin >> n >> m;
		for (int i = 1; i <= n; i++) {
			adj[i].clear();
		}
		res.clear();
		memset(low, 0, sizeof(low));
		memset(disc, 0, sizeof(disc));
		cnt = 0;
		for (int i = 0; i < m; i++) {
			int x, y;
			cin >> x >> y;
			adj[x].push_back(y);
			adj[y].push_back(x);
		}
		Tarjan(1, 0);
		sort(res.begin(), res.end());
		cout << res.size() << endl;
		for (int i = 0; i < res.size(); i++) {
			cout << "(" << res[i].first << " " << res[i].second << ") ";
		}
		cout << endl;
	}
	return 0;
}