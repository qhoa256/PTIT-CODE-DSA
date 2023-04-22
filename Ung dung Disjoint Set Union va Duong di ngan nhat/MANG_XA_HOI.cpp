// Nguyen Huu Quang Hoa - B21DCCN379
#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int t, n, m;
vector<int> adj[100005];
vector<int> tplt;
bool visited[100005];

void DFS(int u)
{
    visited[u] = true;
    tplt.push_back(u);
    for (auto x : adj[u])
    {
        if (!visited[x])
            DFS(x);
    }
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> t;
    while (t--) {
        cin >> n >> m;
        for (int i = 0; i < m; i++)
        {
            int x, y;
            cin >> x >> y;
            adj[x].push_back(y);
            adj[y].push_back(x);
        }
        int ok = 1;
        for (int i = 1; i <= n; i++)
        {
            if (!visited[i])
            {
                tplt.clear();
                DFS(i);
                for (auto x : tplt)
                {
                    if (adj[x].size() != tplt.size() - 1)
                    {
                        ok = 0;
                        break;
                    }
                }
            }
            if (ok == 0) break;
        }
        if (ok) cout << "YES\n";
        else cout << "NO\n";
        tplt.clear();
        memset(visited, 0, sizeof(visited));
        for (int i = 1; i <= n; i++) {
            adj[i].clear();
        }
    }
    return 0;
}