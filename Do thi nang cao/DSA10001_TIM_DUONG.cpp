#include <bits/stdc++.h>
#pragma gcc optimize("Ofast")
using namespace std;

using ll = long long;

int t, n, m;
char a[1005][1005];

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int u1, u2, v1, v2;
int ok;

void DFS(int i , int j , int prev , int cnt)
{
	if (cnt > 3) return;
	if (i == v1 && j == v2) {
		ok = 1;
		return;
	}
	a[i][j] = '*';
	for (int k = 0; k < 4; k++) {
		int i1 = i + dx[k];
		int j1 = j + dy[k];
		if (i1 < 1 || i1 > n || j1 < 1 || j1 > m || a[i1][j1] == '*') continue;
		if (k == prev) DFS(i1, j1, k, cnt);
		else DFS(i1, j1, k, cnt + 1);
	}
	a[i][j] = '.';
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
				if (a[i][j] == 'S') {
					u1 = i;
					u2 = j;
				}
				if (a[i][j] == 'T') {
					v1 = i;
					v2 = j;
				}
			}
		}
		ok = 0;
		DFS(u1, u2, -1, 0);
		if (ok) cout << "YES\n";
		else cout << "NO\n";
	}
	return 0;
}