// Nguyen Huu Quang Hoa - B21DCCN379
#include <bits/stdc++.h>
using namespace std;

using ll = long long;

bool visited[1005];
vector<int> adj[1005];

void DFS(int u)
{
    visited[u] = true;
    for (auto x : adj[u])
    {
        if (!visited[x])
            DFS(x);
    }
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
        int v, e;
        cin >> v >> e;
        for (int i = 1; i <= v; i++)
        {
            visited[i] = false;
            adj[i].clear();
        }
        for (int i = 1; i <= e; i++)
        {
            int x, y;
            cin >> x >> y;
            adj[x].push_back(y);
            adj[y].push_back(x);
        }
        int tplt = 0;
        for (int i = 1; i <= v; i++)
        {
            if (!visited[i])
            {
                tplt++;
                DFS(i);
            }
        }
        cout << tplt << endl;
    }
    return 0;
}