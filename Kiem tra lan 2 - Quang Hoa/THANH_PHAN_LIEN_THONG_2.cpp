#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int n, m;
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
	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		int x, y;
		cin >> x >> y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
// Dinh tru
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
		cout << dem << endl;
		memset(visited, 0, sizeof(visited));
	}
	return 0;
}