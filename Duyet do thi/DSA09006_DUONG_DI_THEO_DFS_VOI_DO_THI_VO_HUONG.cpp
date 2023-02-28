// Nguyen Huu Quang Hoa - B21DCCN379
#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int v, e, s, t;
int parent[1005];
vector<int> adj[1005];
bool visited[1005];

void DFS(int u)
{
    visited[u] = true;
    for (auto x : adj[u])
    {
        if (!visited[x])
        {
            parent[x] = u;
            DFS(x);
        }
    }
}

void findPath(int s, int t)
{
    if (!visited[t])
        cout << -1;
    else
    {
        vector<int> res;
        while (t != s)
        {
            res.push_back(t);
            t = parent[t];
        }
        res.push_back(s);
        for (int i = res.size() - 1; i >= 0; i--)
        {
            cout << res[i] << " ";
        }
    }
    cout << endl;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int test;
    cin >> test;
    while (test--)
    {
        cin >> v >> e >> s >> t;
        for (int i = 1; i <= v; i++)
        {
            adj[i].clear();
            parent[i] = 1;
            visited[i] = false;
        }
        for (int i = 1; i <= e; i++)
        {
            int x, y;
            cin >> x >> y;
            adj[x].push_back(y);
            adj[y].push_back(x);
        }
        DFS(s);
        findPath(s, t);
    }
    return 0;
}