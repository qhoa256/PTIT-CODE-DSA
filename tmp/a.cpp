#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int n, c[1005][1005], cmin = 1e9, visited[1005], x[1005], ans = 1e9;

void Try(int i, int sum) {
    for (int j = 2; j <= n; j++) {
        if (!visited[j]) {
            x[i] = j;
            visited[j] = 1;
            if (i == n) {
                ans = min(ans, sum + c[x[i - 1]][x[i]] + c[x[n]][1]);
            } else if (sum + (n - i)*cmin < ans)
                Try(i + 1, sum + c[x[i - 1]][x[i]]);
            visited[j] = 0;
        }
    }
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> c[i][j];
            cmin = min(cmin, c[i][j]);
        }
    }
    x[1] = 1;
    Try(2, 0);
    cout << ans;
    return 0;
}