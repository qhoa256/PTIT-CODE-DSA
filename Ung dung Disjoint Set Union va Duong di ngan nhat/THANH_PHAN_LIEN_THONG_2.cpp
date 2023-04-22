#include <bits/stdc++.h>
#pragma gcc optimize("Ofast")
using namespace std;

using ll = long long;

int n, m;
int visited[100005];
vector<int>adj[100005];

void DFS(int u) {
	stack<int>st;
	st.push(u);
	visited[u] = 1;
	while (!st.empty()) {
		int x = st.top();
		st.pop();
		for (auto &y : adj[x]) {
			if (!visited[y]) {
				visited[y] = 1;
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
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	for (int i = 1; i <= n; i++) {
		int tplt = 0;
		visited[i] = 1;
		for (int i = 1; i <= n; i++) {
			if (!visited[i]) {
				tplt++;
				DFS(i);
			}
		}
		cout << tplt << endl;
		memset(visited, 0, sizeof(visited));
	}
	return 0;
}