// Nguyen Huu Quang Hoa - B21DCCN379
#include <bits/stdc++.h>
using namespace std;

using ll = long long;

bool visited[1005];
vector<int> adj[1005];
int v, e;

void BFS(int u)
{
    queue<int> q;
    visited[u] = true;
    q.push(u);
    while (!q.empty())
    {
        int k = q.front();
        q.pop();
        for (auto x : adj[k])
        {
            if (!visited[x])
            {
                visited[x] = true;
                q.push(x);
            }
        }
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
                BFS(i);
            }
        }
        cout << tplt << endl;
    }
    return 0;
}