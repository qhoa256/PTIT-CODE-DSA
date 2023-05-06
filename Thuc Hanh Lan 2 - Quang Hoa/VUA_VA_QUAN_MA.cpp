#include <bits/stdc++.h>
#pragma gcc optimize("Ofast")
using namespace std;

using ll = long long;

int n;

int mx[8] = { -1, -2, -2, -1, 1, 2, 2, 1};
int my[8] = { -2, -1, 1, 2, 2, 1, -1, -2};

int vx[8] = {1, -1, 0, 0, 1, -1, 1, -1};
int vy[8] = {1, 1, 1, -1, -1, -1, 0, 0};

int dp1[1005][1005];
int dp2[1005][1005];

int flag1[1005][1005];
int flag2[1005][1005];

char a[1005][1005];

int xm, ym, xv, yv;

int ans = 1e9;

void King(int i, int j) {
	queue<pair<int, int>>q;
	q.push({i, j});
	flag1[i][j] = 0;
	while (!q.empty()) {
		auto x = q.front();
		q.pop();
		int a = x.first;
		int b = x.second;
		for (int k = 0; k < 8; k++) {
			int i1 = a + vx[k];
			int j1 = b + vy[k];
			if (i1 < 1 || i1 > n || j1 < 1 || j1 > n || flag1[i1][j1]) continue;
			dp1[i1][j1] = dp1[a][b] + 1;
			q.push({i1, j1});
			flag1[i1][j1] = 1;
		}
	}
	return;
}

void Knight(int i, int j) {
	queue<pair<int, int>>q;
	q.push({i, j});
	flag2[i][j] = 0;
	while (!q.empty()) {
		auto x = q.front();
		q.pop();
		int a = x.first;
		int b = x.second;
		for (int k = 0; k < 8; k++) {
			int i1 = a + mx[k];
			int j1 = b + my[k];
			if (i1 < 1 || i1 > n || j1 < 1 || j1 > n || flag2[i1][j1]) continue;
			dp2[i1][j1] = dp2[a][b] + 1;
			q.push({i1, j1});
			flag2[i1][j1] = 1;
		}
	}
	return;
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
			cin >> a[i][j];
			if (a[i][j] == '#') {
				flag1[i][j] = flag2[i][j] = 1;
			}
			else if (a[i][j] == 'M') {
				xm = i; ym = j;
			} else if (a[i][j] == 'T') {
				xv = i;
				yv = j;
			}
		}
	}
	King(xv, yv);
	Knight(xm, ym);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (dp1[i][j] == dp2[i][j] && dp1[i][j] != 0) {
				ans = min(ans, dp1[i][j]);
			}
		}
	}
	cout << ans << endl;
	return 0;
}