#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int t, v, e, m;
int adj[1005][1005];
vector<pair<int, int>>p;
int deg[1005];
int color[1005];
int main()
{
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> t;
  while (t--) {
    cin >> v >> e >> m;
    for (int i = 1; i <= e; i++) {
      int x, y;
      cin >> x >> y;
      adj[x][y] = adj[y][x] = 1;
      deg[y]++;
      deg[x]++;
    }
    for (int i = 1; i <= v; i++) {
      p.push_back({i, deg[i]});
    }
    sort(p.begin(), p.end(), [](pair<int, int>a, pair<int, int>b)->bool{
      return a.second > b.second;
    });
    int cnt = 0;
    for (auto x : p) {
      auto a = x.first;
      if (color[a] == 0) {
        cnt++;
        color[a] = cnt;
        for (int i = 1; i <= v; i++) {
          if (color[i] == 0 && adj[a][i] == 0) {
            color[i] = cnt;
          }
        }
      }
    }
    if (cnt <= m) cout << "YES\n";
    else cout << "NO\n";
    memset(adj, 0, sizeof(adj));
    memset(deg, 0, sizeof(deg));
    memset(color, 0, sizeof(color));
    p.clear();
  }
  return 0;
}