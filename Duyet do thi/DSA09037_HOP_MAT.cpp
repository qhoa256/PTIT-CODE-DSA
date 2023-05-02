#include <bits/stdc++.h>
#pragma gcc optimize("Ofast")
using namespace std;

using ll = long long;

int k, n, m;
vector<int>adj[1005];
int visited[1005];
int cnt[1005];

void DFS(int u) {
	visited[u] = 1;
	cnt[u]++;
	for (auto &x : adj[u]) {
		if (!visited[x]) {
			DFS(x);
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
	cin >> k >> n >> m;
	vector<int>v;
	for (int i = 0; i < k; i++) {
		int x;
		cin >> x;
		v.push_back(x);
	}
	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		adj[x].push_back(y);
	}
	for (int i = 0; i < v.size(); i++) {
		memset(visited, 0, sizeof(visited));
		DFS(v[i]);
	}
	int res = 0;
	for (int i = 1; i <= n; i++) {
		if (cnt[i] == k) {
			res++;
		}
	}
	cout << res;
	return 0;
}