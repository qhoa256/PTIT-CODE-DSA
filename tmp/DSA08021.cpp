#include <bits/stdc++.h>
#pragma gcc optimize("Ofast")
using namespace std;

using ll = long long;

int t, n, m, a[1005][1005], dp[1005][1005]; //Mang dp luu so buoc it nhat de di den vi tri (i,j)
void BFS(int i, int j) {
    queue<pair<int, int>>q;
    q.push({i, j});
    dp[i][j] = 0; //So buoc de di tu (i,j) den (i,j) la bang 0
    // Mang dp[i][j] cung danh dau la o (i,j) da duoc tham hay chua
    //Neu dp[i][j]==1e9 tuc la chua tham, khac 1e9 la tham roi
    while (!q.empty()) {
        auto top = q.front();
        q.pop();
        int u = top.first, v = top.second;
        if (u == n && v == m) return; // Neu den vi tri cuoi cung roi thi return
        if (dp[u][v + a[u][v]] == 1e9 && v + a[u][v] <= m) {
            dp[u][v + a[u][v]] = dp[u][v] + 1;
            // So buoc tai vi tri dp[u][v+a[u][v]] se bang so buoc cua vi tri truoc no cong them 1 buoc
            q.push({u, v + a[u][v]});
        }
        if (dp[u + a[u][v]][v] == 1e9 && u + a[u][v] <= n) {
            dp[u + a[u][v]][v] = dp[u][v] + 1;
            q.push({u + a[u][v], v});
        }
    }
    return;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> t;
    while (t--) {
        cin >> n >> m;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                cin >> a[i][j];
            }
        }
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                dp[i][j] = 1e9;
                //Khoi tao mang dp voi 2 muc dich:
                //*Muc dich 1: Danh dau vi tri i,j duoc tham hay chua
                //*Muc dich 2: Khong co duong di den o (i,j)
            }
        }
        BFS(1, 1);
        if (dp[n][m] != 1e9) {
            cout << dp[n][m] << endl;
        } else {
            cout << -1 << endl;
        }
    }
    return 0;
}