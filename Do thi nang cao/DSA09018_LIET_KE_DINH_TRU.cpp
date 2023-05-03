#include <bits/stdc++.h>
#pragma gcc optimize("Ofast")
using namespace std;

using ll = long long;

vector<int>adj[1005];
int t, n, m;
int visited[1005];

void DFS(int u) {
	stack<int>st;
	st.push(u);
	visited[u] = 1;
	while (!st.empty()) {
		int y = st.top();
		st.pop();
		for (auto &x : adj[y]) {
			if (!visited[x]) {
				visited[x] = 1;
				st.push(x);
				st.push(y);
				break;
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
		for (int i = 0; i < m; i++) {
			int x, y;
			cin >> x >> y;
			adj[x].push_back(y);
			adj[y].push_back(x);
		}
		for (int i = 1; i <= n; i++) {
			memset(visited, 0, sizeof(visited));
			visited[i] = 1;
			int cnt = 0;
			for (int j = 1; j <= n; j++) {
				if (!visited[j]) {
					cnt++;
					DFS(j);
				}
			}
			if (cnt > 1) {
				cout << i << " ";
			}
		}
		cout << endl;
		for (int i = 1; i <= n; i++) {
			adj[i].clear();
		}
	}
	return 0;
}