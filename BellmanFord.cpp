#include <bits/stdc++.h>
#pragma gcc optimize("Ofast")
using namespace std;

using ll = long long;

int t, n, m;
struct Edge {
	int x, y, w;
};
vector<Edge>E;
int d[1005];
void bellmanFord(int u) {
	fill(d + 1, d + n + 1, 1e9);
	d[u] = 0;
	for (int i = 0; i < n - 1; i++) {
		for (auto &e : E) {
			int u = e.x;
			int v = e.y;
			int w = e.w;
			if (d[u] != 1e9 && d[v] > d[u] + w) {
				d[v] = d[u] + w;
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
			int x, y, w;
			cin >> x >> y >> w;
			E.push_back({x, y, w});
		}
		bellmanFord(1);
		for (int i = 1; i <= n; i++) {
			cout << d[i] << " ";
		}
	}
	return 0;
}