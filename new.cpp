#include <bits/stdc++.h>
#define ll long long
#pragma GCC optimize("Ofast")
const ll mod = (ll)1e9 + 7;
#define endl "\n"
#define all(v) v.begin(), v.end()
#define ms(a) memset(a, 0, sizeof(a))
#define faster()                  \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);
using namespace std;
ll n, m;
set<ll> adj[1000001], s;
queue<ll> qe;
int main()
{
    faster();
    cin >> n >> m;
    for (ll i = 0; i < m; i++)
    {
        ll x, y;
        cin >> x >> y;
        adj[x].insert(y);
        adj[y].insert(x);
    }
    for (ll i = 1; i <= n; i++)
    {
        s.insert(i);
    }
    vector<ll> path;
    for (ll i = 1; i <= n; i++)
    {
        if (s.count(i))
        {
            qe.push(i);
            s.erase(i);
            ll cnt = 0;
            while (qe.size())
            {
                vector<ll> del;
                ll dinh = qe.front();
                qe.pop();
                cnt++;
                for (auto v : s)
                {
                    if (adj[dinh].count(v) == 0)
                    {
                        qe.push(v);
                        del.push_back(v);
                    }
                }
                for (auto v : del)
                    s.erase(v);
            }
            path.push_back(cnt);
        }
    }
    cout << path.size() << endl;
    sort(all(path));
    for (auto x : path)
        cout << x << " ";
}