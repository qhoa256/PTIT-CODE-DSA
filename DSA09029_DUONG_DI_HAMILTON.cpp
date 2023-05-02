#include <bits/stdc++.h>
#pragma gcc optimize("Ofast")
using namespace std;

using ll = long long;

int t, n, m;
vector<int>adj[10005];
int visited[10005];
int x[10005];
int ok;
void hamilton(int k) {
	for (auto &v : adj[x[k - 1]]) {
		if (k == n + 1) {
			cout << "QH\n";
			if (v == x[1]) {
				ok = 1;
				return;
			}
		} else {
			if (!visited[v]) {
				x[k] = v;
				visited[v] = 1;
				hamilton(k + 1);
				visited[v] = 0;
			}
		}
	}
}

void Lke(int u) {
	x[1] = u;
	visited[u] = 1;
	hamilton(2);
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
		for (int i = 1; i <= n; i++) {
			adj[i].clear();
		}
		memset(visited, 0, sizeof(visited));
		ok = 0;
		for (int i = 0; i < m; i++) {
			int x, y;
			cin >> x >> y;
			adj[x].push_back(y);
			adj[y].push_back(x);
		}
		// x[1] = 1;
		// visited[1] = 1;
		// hamilton(2);
		Lke(1);
		cout << ok << endl;
	}
	return 0;
}