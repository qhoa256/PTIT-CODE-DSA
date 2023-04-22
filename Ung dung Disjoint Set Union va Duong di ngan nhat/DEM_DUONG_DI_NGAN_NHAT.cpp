#include <bits/stdc++.h>

using namespace std;

using ll = long long;

vector<pair<ll, ll>>adj[100005];
ll route[100005];
ll n, m, s;
ll d[100005];
void Dijkstra(ll s) {
    fill(d + 1, d + n + 1, 1e18);
    d[s] = 0;
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>>pq;
    pq.push({d[s], s});
    route[1] = 1;
    while (!pq.empty()) {
        ll u = pq.top().second;
        ll du = pq.top().first;
        pq.pop();
        if (du > d[u]) continue;
        for (auto x : adj[u]) {
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
    for (ll i = 0; i < m; i++) {
        ll x, y, w;
        cin >> x >> y >> w;
        adj[x].push_back({y, w});
        adj[y].push_back({x, w});
    }
    Dijkstra(1);
    cout << d[n] << " " << route[n];
    return 0;
}