// Nguyen Huu Quang Hoa - B21DCCN379
#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int a[1005][1005];
pair<int, int> path[8] = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}, {-1, -1}, {-1, 1}, {1, 1}, {1, -1}};
int n, m;

void DFS(int i, int j)
{
    a[i][j] = 0;
    for (int k = 0; k < 8; k++)
    {
        int i1 = i + path[k].first;
        int j1 = j + path[k].second;
        if (i1 >= 1 && i1 <= n && j1 >= 1 && j1 <= m && a[i1][j1])
        {
            DFS(i1, j1);
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
        cin >> n >> m;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                cin >> a[i][j];
            }
        }
        int res = 0;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                if (a[i][j])
                {
                    res++;
                    DFS(i, j);
                }
            }
        }
        cout << res << endl;
    }
    return 0;
}