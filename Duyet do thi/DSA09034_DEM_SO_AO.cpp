#include <bits/stdc++.h>

using namespace std;

using ll = long long;

/* 0 1
   0 -1
   1 0
   -1 0
   1 1
   1 -1
   -1 -1
   -1 1
*/
int dx[8] = {0, 0, 1, -1, 1, 1, -1, -1};
int dy[8] = {1, -1, 0, 0, 1, -1, -1, 1};
char a[1005][1005];
int n, m;
void DFS(int i, int j) {
	a[i][j] = '.';
	for (int k = 0; k < 8; k++) {
		int i1 = i + dx[k];
		int j1 = j + dy[k];
		if (i1 >= 1 && i1 <= n && j1 >= 1 && j1 <= m && a[i1][j1] == 'W') {
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
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> a[i][j];
		}
	}
	int cnt = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (a[i][j] == 'W') {
				cnt++;
				DFS(i, j);
			}
		}
	}
	cout << cnt;
	return 0;
}