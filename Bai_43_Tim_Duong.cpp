#include <bits/stdc++.h>
#pragma gcc optimize("Ofast")
using namespace std;

using ll = long long;

int n, m;
char a[1005][1005];

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int u1, u2, v1, v2;
int ok = 0;

int check(int k) {
	if (k == 0) return 'D';
	else if (k == 1) return 'U';
	else if (k == 2) return 'R';
	else return 'L';
}

void DFS(int i , int j , char prev , int cnt)
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
		char tmp = check(k);
		if (tmp == prev) DFS(i1, j1, tmp, cnt);
		else DFS(i1, j1, tmp, cnt + 1);
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
	DFS(u1, u2, '0', 0);
	if (ok) cout << "YES";
	else cout << "NO";
	return 0;
}