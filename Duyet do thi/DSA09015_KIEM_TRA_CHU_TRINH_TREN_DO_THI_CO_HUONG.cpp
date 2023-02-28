// Nguyen Huu Quang Hoa - B21DCCN379
#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int v, e;
vector<int> adj[1005];
int color[1005];
int parent[1005];

bool DFS(int u)
{
    color[u] = 1;
    for (auto x : adj[u])
    {
        if (!color[x])
        {
            parent[x] = u;
            if (DFS(x))
                return true;
        }
        else
        {
            if (color[x] == 1)
                return true;
        }
    }
    color[u] = 2;
    return false;
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
        for (int i = 1; i <= v; i++)
        {
            adj[i].clear();
            color[i] = 0;
            parent[i] = 0;
        }
        for (int i = 1; i <= e; i++)
        {
            int x, y;
            cin >> x >> y;
            adj[x].push_back(y);
        }
        bool ok = false;
        for (int i = 1; i <= v; i++)
        {
            if (!color[i] && DFS(i))
            {
                ok = true;
                break;
            }
        }
        if (ok)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    return 0;
}