#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int t, n, m;
vector<int> adj[1000001];
int visited[1000001];

void DFS(int u)
{
	visited[u] = 1;
	for (auto x : adj[u])
	{
		if (!visited[x])
			DFS(x);
	}
}
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin >> t;
	while (t--) {
		cin >> n >> m;
		for (int i = 0; i < m; i++)
		{
			int x, y;
			cin >> x >> y;
			adj[x].push_back(y);
			adj[y].push_back(x);
		}
		int tplt = 0;
		for (int i = 1; i <= n; i++)
		{
			if (!visited[i])
			{
				tplt++;
				DFS(i);
			}
		}
		int ans = 0;
		int pos = 0;
		int ok = 0;
		for (int i = 1; i <= n; i++)
		{
			visited[i] = 1;
			int dem = 0;
			for (int j = 1; j <= n; j++)
			{
				if (!visited[j])
				{
					dem++;
					DFS(j);
				}
			}
			if (dem > tplt) {
				ok = 1;
				if (ans < dem) {
					ans = dem;
					pos = i;
				}
			}
			memset(visited, false, sizeof(visited));
		}
		if (ok)
			cout << pos << endl;
		else cout << 0 << endl;
		memset(visited, false, sizeof(visited));
		for (int i = 1; i <= n; i++) {
			adj[i].clear();
		}
	}
	return 0;
}