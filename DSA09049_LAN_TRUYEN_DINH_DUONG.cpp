#include <bits/stdc++.h>
#pragma gcc optimize("Ofast")
#define endl '\n'
using namespace std;

using ll = long long;

int n;
vector<int>adj[1000005];
ll sum[1000005];
ll val[1000005];

void DFS(int u) {
    for (auto &x : adj[u]) {
        DFS(x);
        sum[u] += sum[x] + 1;
        val[u] += val[x];
    }
    val[u] += sum[u];
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
    for (int i = 2; i <= n; i++) {
        int x;
        cin >> x;
        adj[x].push_back(i);
    }
    for (int i = 1; i <= n; i++) {
        sum[i] = 0;
        val[i] = 1;
    }
    DFS(1);
    for (int i = 1; i <= n; i++) {
        cout << val[i] << " ";
    }
    return 0;
}