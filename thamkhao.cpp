#include <bits/stdc++.h>
#define ll long long
#pragma GCC optimize("Ofast")
const ll mod = (ll)1e9 + 7;
#define endl "\n"
#define maxn 1000006
#define _oo LLONG_MIN
#define oo LLONG_MAX - 9
#define bit(x, i) ((x >> i) & 1)
#define all(v) v.begin(), v.end()
#define ms(a) memset(a, 0, sizeof(a))
#define faster()                  \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);
using namespace std;
ll n, res = 0;
bool visited[100001];
vector<ll> adj[100001];
void dfs(ll u, ll cnt)
{
    res = max(res, cnt);
    visited[u] = true;
    for (auto &x : adj[u])
    {
        if (!visited[x])
            dfs(x, cnt + 1);
    }
}
int main()
{
    faster();
    ll t;
    cin >> t;
    while (t--)
    {
        cin >> n;
        for (ll i = 1; i <= n - 1; i++)
        {
            ll x, y;
            cin >> x >> y;
            adj[x].push_back(y);
            adj[y].push_back(x);
        }
        dfs(1, 0);
        cout << res << endl;
        res = 0;
        for (auto &x : adj)
            x.clear();
        ms(visited);
    }
}