#include <bits/stdc++.h>

using namespace std;

using ll = long long;
int n;
int D[1005][1005];
int A[1005][1005];

void floyd() {
	for (int k = 1; k <= n; k++) {
		for (int u = 1; u <= n; u++) {
			for (int v = 1; v <= n; v++) {
				if (D[u][v] > D[u][k] + D[k][v]) {
					D[u][v] = D[u][k] + D[k][v];
				}
				A[u][v] = max(A[u][v], max(A[u][k], A[k][v]));
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
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i == j) {
				D[i][j] = 0;
				A[i][j] = 0;
			} else {
				D[i][j] = 1e9;
				A[i][j] = 1e9;
			}
		}
	}
	for (int i = 1; i <= n - 1; i++) {
		int x, y, z;
		cin >> x >> y >> z;
		D[x][y] = D[y][x] = z;
		A[x][y] = A[y][x] = z;
	}
	floyd();
	int q;
	cin >> q;
	while (q--) {
		int x, y;
		cin >> x >> y;
		cout << D[x][y] << " " << A[x][y] << endl;
	}
	return 0;
}