// Nguyen Huu Quang Hoa - B21DCCN379
#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int a[1005][1005];
vector<int> adj[1005];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> a[i][j];
            if (a[i][j])
            {
                adj[i].push_back(j);
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (auto x : adj[i])
            cout << x << " ";
        cout << endl;
    }
    return 0;
}