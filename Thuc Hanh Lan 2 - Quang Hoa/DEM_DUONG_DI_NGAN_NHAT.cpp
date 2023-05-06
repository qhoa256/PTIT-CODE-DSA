#include <bits/stdc++.h>
#pragma gcc optimize("Ofast")
using namespace std;

using ll = long long;

ll n, m;
vector<pair<ll, ll>>adj[1000005];
ll route[1000005];
ll d[1000005];
void dijkstra(ll i) {
	fill(d + 1, d + n + 1, 1e18);
	priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll> >> pq;
	d[i] = 0;
	pq.push({d[i], i});
	route[i] = 1;
	while (!pq.empty()) {
		auto top = pq.top();
		pq.pop();
		ll u = top.second;
		ll du = top.first;
		if (du > d[u]) continue;
		for (auto &x : adj[u]) {
			ll v = x.first;
			ll w = x.second;
			if (d[v] == d[u] + w) {
				route[v] += route[u];
			}
			if (d[v] > d[u] + w) {
				d[v] = d[u] + w;
				route[v] = route[u];
				pq.push({d[v], v});
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
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		ll x, y, c;
		cin >> x >> y >> c;
		adj[x].push_back({y, c});
		adj[y].push_back({x, c});
	}
	dijkstra(1);
	cout << d[n] << " " << route[n] << endl;
	return 0;
}