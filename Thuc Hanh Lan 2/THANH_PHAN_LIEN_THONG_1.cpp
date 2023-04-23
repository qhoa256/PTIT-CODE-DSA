#include <bits/stdc++.h>

using namespace std;

using ll = long long;

vector<int>p[1005];
bool visited[1005];

void DFS(int u) {
	visited[u] = true;
	for (auto x : p[u]) {
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
	int n, m, e;
	cin >> n >> m >> e;
	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		p[x].push_back(y);
		p[y].push_back(x);
	}
	DFS(e);
	int ok = 0;
	for (int i = 1; i <= n; i++) {
		if (!visited[i]) {
			ok = 1;
			cout << i << endl;
		}
	}
	if (!ok) cout << ok;
	return 0;
}