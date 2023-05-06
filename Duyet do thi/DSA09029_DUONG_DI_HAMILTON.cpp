#include <bits/stdc++.h>
#pragma gcc optimize("Ofast")
using namespace std;

using ll = long long;

int t, n, m;
vector<int>adj[10005];
int visited[10005];
int x[10005];
int ok;
bool hamilton(int k) {
	for (auto &v : adj[x[k - 1]]) {
		if (k == n + 1) {
			return true;
		} else {
			if (!visited[v]) {
				x[k] = v;
				visited[v] = 1;
				if (hamilton(k + 1)) return true;
				visited[v] = 0;
			}
		}
	}
	return false;
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
		for (int i = 0; i < m; i++) {
			int x, y;
			cin >> x >> y;
			adj[x].push_back(y);
			adj[y].push_back(x);
		}
		ok = 0;
		for (int i = 1; i <= n; i++) {
			memset(visited, 0, sizeof(visited));
			memset(x, 0, sizeof(x));
			x[1] = i;
			visited[i] = 1;
			if (hamilton(2)) {
				ok = 1;
				break;
			}
		}
		cout << ok << endl;
	}
	return 0;
}