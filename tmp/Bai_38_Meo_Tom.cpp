#include <bits/stdc++.h>
#pragma gcc optimize("Ofast")
using namespace std;

using ll = long long;

int n, m, crook[1005];
vector<int>adj[1005];
int visited[1005];

int res = 0;

void DFS(int u, int cnt) {
	visited[u] = 1;
	if (cnt > m) return;
	if (adj[u].size() == 1 && u != 1) {
		res++;
	}
	for (auto &x : adj[u]) {
		if (!visited[x]) {
			if (crook[x]) DFS(x, cnt + 1);
			else DFS(x, 0);
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
	for (int i = 1; i <= n; i++) {
		cin >> crook[i];
	}
	for (int i = 1; i <= n - 1; i++) {
		int x, y;
		cin >> x >> y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	DFS(1, crook[1]);
	cout << res;
	return 0;
}