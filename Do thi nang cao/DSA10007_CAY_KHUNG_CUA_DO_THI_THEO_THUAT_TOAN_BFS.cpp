#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int t, n, m, u;
vector<int>adj[1005];
bool visited[1005];
vector<pair<int, int>>res;
void BFS(int u) {
	queue<int>q;
	q.push(u);
	visited[u] = true;
	while (!q.empty()) {
		int a = q.front();
		q.pop();
		for (auto &x : adj[a]) {
			if (!visited[x]) {
				visited[x] = true;
				q.push(x);
				res.push_back({a, x});
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
		cin >> n >> m >> u;
		for (int i = 1; i <= m; i++) {
			int x, y;
			cin >> x >> y;
			adj[x].push_back(y);
			adj[y].push_back(x);
		}
		BFS(u);
		if (res.size() == n - 1) {
			for (auto &x : res) {
				cout << x.first << " " << x.second << endl;
			}
		} else {
			cout << -1 << endl;
		}
		res.clear();
		memset(visited, 0, sizeof(visited));
		for (int i = 1; i <= n; i++) {
			adj[i].clear();
		}
	}
	return 0;
}