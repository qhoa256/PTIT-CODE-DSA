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
        }
        DFS(u);
        cout << endl;
        memset(adj, 0, sizeof(adj));
        memset(visited, false, sizeof(visited));
    }
    return 0;
}