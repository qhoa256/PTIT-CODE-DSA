#include <bits/stdc++.h>
#pragma gcc optimize("Ofast")
using namespace std;

using ll = long long;

int n, m, q, D[1005][1005];

void floyd() {
	for (int k = 1; k <= n; k++) {
		for (int u = 1; u <= n; u++) {
			for (int v = 1; v <= n; v++) {
				D[u][v] = min(D[u][v], max(D[u][k], D[k][v]));
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
	cin >> n >> m >> q;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i == j) D[i][j] = 0;
			else D[i][j] = D[j][i] = 1e9;
		}
	}
	for (int i = 0; i < m; i++) {
		int x, y, w;
		cin >> x >> y >> w;
		D[x][y] = w;
	}
	floyd();
	while (q--) {
		int x, y;
		cin >> x >> y;
		if (D[x][y] == 1e9) cout << -1;
		else cout << D[x][y];
		cout << endl;
	}
	return 0;
}