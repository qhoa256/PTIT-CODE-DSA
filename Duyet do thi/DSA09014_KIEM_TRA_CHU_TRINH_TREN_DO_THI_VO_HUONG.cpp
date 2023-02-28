// Nguyen Huu Quang Hoa - B21DCCN379
#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int parent[1005];
int sz[1005];
int v, e;
void init()
{
    for (int i = 1; i <= v; i++)
    {
        parent[i] = i;
        sz[i] = 1;
    }
}
int find(int u)
{
    if (u == parent[u])
        return u;
    else
        return parent[u] = find(parent[u]);
}

bool Union(int u, int v)
{
    u = find(u);
    v = find(v);
    if (u == v)
        return false;
    if (sz[u] < sz[v])
    {
        swap(u, v);
    }
    sz[u] += sz[v];
    parent[v] = u;
    return true;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
    {
        cin >> v >> e;
        init();
        bool ok = false;
        for (int i = 1; i <= e; i++)
        {
            int x, y;
            cin >> x >> y;
            if (!Union(x, y))
            {
                ok = true;
            }
        }
        if (ok)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
        memset(parent, 0, sizeof(parent));
        memset(sz, 0, sizeof(sz));
    }
    return 0;
}