#include <bits/stdc++.h>

using namespace std;

using ll = long long;
int t, n, m;
int D[1005][1005];

void floyd() {
	for (int k = 1; k <= n; k++) {
		for (int u = 1; u <= n; u++) {
			for (int v = 1; v <= n; v++) {
				if (D[u][v] > D[u][k] + D[k][v]) {
					D[u][v] = D[u][k] + D[k][v];
				}
			}
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
			for (int j = 1; j <= n; j++) {
				if (i == j) {
					D[i][j] = 0;
				} else {
					D[i][j] = 1e9;
				}
			}
		}
		for (int i = 1; i <= m; i++) {
			int x, y;
			cin >> x >> y;
			D[x][y] = 1;
		}
		floyd();
		double res = 0, cnt = 0;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (D[i][j] != 1e9 && i != j) {
					res += 1.0 * D[i][j];
					cnt++;
				}
			}
		}
		cout << fixed << setprecision(2) << res / cnt << endl;
	}
	return 0;
}