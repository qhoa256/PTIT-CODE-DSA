// Nguyen Huu Quang Hoa - B21DCCN379
#include <bits/stdc++.h>
using namespace std;

using ll = long long;

vector<int> adj[1005];
int tplt[1005];

int cnt;
void DFS(int u)
{
    tplt[u] = cnt;
    for (auto x : adj[u])
    {
        if (!tplt[x])
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
        cin.ignore();
        int n, m;
        cin >> n >> m;
        cnt = 1;
        for (int i = 1; i <= n; i++)
        {
            adj[i].clear();
            tplt[i] = 0;
        }
        for (int i = 1; i <= m; i++)
        {
            int x, y;
            cin >> x >> y;
            adj[x].push_back(y);
            adj[y].push_back(x);
        }
        for (int i = 1; i <= n; i++)
        {
            if (!tplt[i])
            {
                DFS(i);
                cnt++;
            }
        }
        int q;
        cin >> q;
        while (q--)
        {
            int a, b;
            cin >> a >> b;
            if (tplt[a] == tplt[b])
                cout << "YES\n";
            else
                cout << "NO\n";
        }
    }
    return 0;
}