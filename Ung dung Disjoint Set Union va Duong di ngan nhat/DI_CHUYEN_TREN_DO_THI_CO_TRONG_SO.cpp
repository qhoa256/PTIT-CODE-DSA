#include <bits/stdc++.h>
#define ll long long
ll n, m, q;
struct edge
{
    ll x, y, w;
};
vector<edge> edges;
ll d2[1001][1001];
void init()
{
    cin >> n >> m >> q;
    for (ll i = 1; i <= n; i++)
    {
        for (ll j = 1; j <= n; j++)
        {
            if (i == j)
                d2[i][j] = 0;
            else
                d2[i][j] = (ll)1e18 + 5;
        }
    }
    for (int i = 0; i < m; i++)
    {
        ll x, y, w;
        cin >> x >> y >> w;
        edges.push_back({x, y, w});
        d2[x][y] = w;
    }
}
// Floyd tim duong di cua moi cap dinh tren do thi
void Floyd()
{
    for (ll k = 1; k <= n; k++)
    {
        for (ll i = 1; i <= n; i++)
        {
            for (ll j = 1; j <= n; j++)
            {
                d2[i][j] = min(d2[i][j], max(d2[i][k], d2[k][j]));
            }
        }
    }
    while (q--)
    {
        ll x, y;
        cin >> x >> y;
        if (d2[x][y] == 1e18 + 5)
            cout << -1 << endl;
        else
            cout << d2[x][y] << endl;
    }
}

int main()
{
    init();
    Floyd();
}