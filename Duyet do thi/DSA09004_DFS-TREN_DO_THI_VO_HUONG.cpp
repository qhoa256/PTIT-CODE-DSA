// Nguyen Huu Quang Hoa - B21DCCN379
#include <bits/stdc++.h>
using namespace std;

using ll = long long;

vector<int> adj[1005];
bool visited[1005];
void DFS(int u)
{
    visited[u] = true;
    cout << u << " ";
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
        int v, e, u;
        cin >> v >> e >> u;
        while (e--)
        {
            int x, y;
            cin >> x >> y;
            adj[x].push_back(y);
            adj[y].push_back(x);
        }
        DFS(u);
        cout << endl;
        memset(visited, false, sizeof(visited));
        memset(adj, 0, sizeof(adj));
    }
    return 0;
}