// Nguyen Huu Quang Hoa - B21DCCN379
#include <bits/stdc++.h>
using namespace std;

using ll = long long;

vector<int> adj[1005];
bool visited[1005];

void BFS(int u)
{
    queue<int> q;
    q.push(u);
    visited[u] = true;
    while (!q.empty())
    {
        int x = q.front();
        q.pop();
        cout << x << " ";
        for (auto k : adj[x])
        {
            if (!visited[k])
            {
                q.push(k);
                visited[k] = true;
            }
        }
    }
    cout << endl;
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
        for (int i = 1; i <= v; i++)
        {
            adj[i].clear();
            visited[i] = false;
        }
        while (e--)
        {
            int x, y;
            cin >> x >> y;
            adj[x].push_back(y);
        }
        BFS(u);
    }
    return 0;
}