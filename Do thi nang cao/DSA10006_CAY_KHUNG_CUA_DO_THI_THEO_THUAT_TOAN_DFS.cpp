#include <bits/stdc++.h>
#pragma gcc opitmize("Ofast");
using namespace std;

using ll = long long;

int t, n, m, u;
vector<int>adj[1005];
vector<pair<int, int>>res;
bool visited[1005];

// DFS USING STACK
void DFS(int u) {
	stack<int>st;
	st.push(u);
	visited[u] = true;
	while (!st.empty()) {
		int a = st.top();
		st.pop();
		for (auto &x : adj[a]) {
			if (!visited[x]) {
				visited[x] = true;
				st.push(a);
				st.push(x);
				res.push_back({a, x});
				break;
			}
		}
	}
}
/* DFS USING RECURSION
void DFS(int u) {
	visited[u] = true;
	for (auto &x : adj[u]) {
		if (!visited[x]) {
			res.push_back({u, x});
			DFS(x);
		}
	}
*/
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
		DFS(u);
		if (res.size() == n - 1) {
			for (auto &x : res) {
				cout << x.first << " " << x.second << endl;
			}
		} else {
			cout << -1 << endl;
		}
		memset(visited, 0, sizeof(visited));
		for (int i = 1; i <= n; i++) {
			adj[i].clear();
		}
		res.clear();
	}
	return 0;
}