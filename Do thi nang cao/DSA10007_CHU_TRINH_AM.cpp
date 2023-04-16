#include <bits/stdc++.h>

using namespace std;

using ll = long long;

struct Edge {
	int u, v, w;
};

vector<Edge>E;

int test, n, m;
int d[1005];
int bellmanFord(int s) {
	fill(d + 1, d + n + 1, 1e9);
	d[s] = 0;
	for (int t = 1; t < n; t++) {
		for (auto e : E) {
			int u = e.u;
			int v = e.v;
			int w = e.w;
			if (d[u] != 1e9 && d[v] > d[u] + w) {
				d[v] = d[u] + w;
			}
		}
	}
	for (auto e : E) {
		int u = e.u;
		int v = e.v;
		int w = e.w;
		if (d[u] != 1e9 && d[v] > d[u] + w) {
			return 1;
		}
	}
	return 0;
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
	cin >> test;
	while (test--) {
		cin >> n >> m;
		for (int i = 0; i < m; i++) {
			int x, y, w;
			cin >> x >> y >> w;
			Edge e{x, y, w};
			E.push_back(e);
		}
		int check = 0;
		for (int i = 1; i <= n; i++) {
			if (bellmanFord(i)) {
				check = 1;
				break;
			}
		}
		cout << check << endl;
		E.clear();
	}
	return 0;
}