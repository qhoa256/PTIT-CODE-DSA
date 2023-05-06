#include <bits/stdc++.h>
#pragma gcc optimize("Ofast")
#define endl "\n"
using namespace std;

using ll = long long;

int t, n, m;
int parent[100005];
int sz[100005];
struct Edge {
	int u, v;
	double w;
};

vector<Edge>E;

void init() {
	for (int i = 1; i <= n; i++) {
		parent[i] = i;
		sz[i] = 1;
	}
}
int Find(int u) {
	if (u == parent[u]) return u;
	else return parent[u] = Find(parent[u]);
}

bool Union(int u, int v) {
	u = Find(u);
	v = Find(v);
	if (u == v) return false;
	if (sz[u] < sz[v]) swap(u, v);
	sz[u] += sz[v];
	parent[v] = u;
	return true;
}
void Kruskal() {
	sort(E.begin(), E.end(), [](Edge a, Edge b)->bool{
		return a.w < b.w;
	});
	double d = 0;
	int cnt = 0;
	for (auto &e : E) {
		if (cnt == n - 1) break;
		if (Union(e.u, e.v)) {
			d += e.w;
			cnt++;
		}
	}
	cout << fixed << setprecision(6) << d << endl;
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
		cin >> n;
		init();
		E.clear();
		vector<pair<double, double>>p;
		p.push_back({0, 0});
		for (int i = 0; i < n; i++) {
			double x, y;
			cin >> x >> y;
			p.push_back({x, y});
		}
		for (int i = 1; i <= p.size() - 2; i++) {
			for (int j = i + 1; j <= p.size() - 1; j++) {
				double d = sqrt(pow(p[j].first - p[i].first, 2) + pow(p[j].second - p[i].second, 2));
				E.push_back({i, j, d});
			}
		}
		Kruskal();
	}
	return 0;
}