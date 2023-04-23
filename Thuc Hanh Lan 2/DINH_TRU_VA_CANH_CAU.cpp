#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int n, m;
vector<int> adj[1000001];
int visited[1000001];
vector<pair<int, int>> edge;

void DFS(int u)
{
	visited[u] = 1;
	for (auto x : adj[u])
	{
		if (!visited[x])
			DFS(x);
	}
}

void DFS2(int u, int x, int y)
{
	visited[u] = true;
	for (auto z : adj[u])
	{
		if (z == x && u == y || z == y && u == x)
			continue;
		if (!visited[z])
		{
			DFS2(z, x, y);
		}
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
		edge.push_back({x, y});
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
	memset(visited, 0, sizeof(visited));
	int tru = 0; // Dinh tru
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
		memset(visited, false, sizeof(visited));
		if (dem > tplt)
			tru++;
	}
	int cau = 0; // Canh cau
	for (auto e : edge)
	{
		int x = e.first, y = e.second;
		int dem = 0;
		memset(visited, false, sizeof(visited));
		for (int i = 1; i <= n; i++)
		{
			if (!visited[i])
			{
				dem++;
				DFS2(i, x, y);
			}
		}
		if (dem > tplt)
			cau++;
	}
	cout << tru << " " << cau;
	return 0;
}