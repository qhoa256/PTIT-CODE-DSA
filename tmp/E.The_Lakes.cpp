#include <bits/stdc++.h>
#pragma gcc optimize("Ofast")
using namespace std;

using ll = long long;

int dx[4] = { -1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};


int sum;
int ans = -1e9;
int t, n, m;

int a[1005][1005];
int visited[1005][1005];

void DFS(int i, int j) {
	sum += a[i][j];
	a[i][j] = 0;
	for (int k = 0; k < 4; k++) {
		int i1 = i + dx[k];
		int j1 = j + dy[k];
		if (i1 >= 1 && i1 <= n && j1 >= 1 && j1 <= m && a[i1][j1] != 0) {
			DFS(i1, j1);
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
	cin >> t;
	while (t--) {
		cin >> n >> m;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				cin >> a[i][j];
			}
		}
		ans = 0;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				if (a[i][j]) {
					sum = 0;
					DFS(i, j);
					ans = max(ans, sum);
				}
			}
		}
		cout << ans << endl;
	}
	return 0;
}