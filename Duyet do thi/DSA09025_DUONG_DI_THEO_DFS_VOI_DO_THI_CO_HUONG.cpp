// Nguyen Huu Quang Hoa - B21DCCN379
#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int v, e, s, t;
vector<int> adj[1005];
bool visited[1005];
int parent[1005];

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


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int k;
    cin >> k;
    while (k--)
    {
        cin >> v >> e >> s >> t;
        for (int i = 1; i <= v; i++)
        {
            adj[i].clear();
            visited[i] = false;
            parent[i] = 0;
        }
        for (int i = 1; i <= e; i++)
        {
            int x, y;
            cin >> x >> y;
            adj[x].push_back(y);
        }
        DFS(s);
        if (!visited[t])
        {
            cout << -1;
        }
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
    return 0;
}