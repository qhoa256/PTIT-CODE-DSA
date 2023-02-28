#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int t, n, m, res, a[1005][1005];
int vs[1005][1005];
pair<int, int>p[2] = {{1, 0}, {0, 1}};

void nhap() {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> a[i][j];
		}
	}
	memset(vs,1,sizeof(vs));
}

void Try(int i, int j) {
	if (i == n && j == m) res++;
	for (int k = 0; k < 2; k++) {
		int i1 = i + p[k].first;
		int j1 = j + p[k].second;
		if (i1 >= 1 && i <= n && j1 >= 1 && j1 <= m && vs[i1][j1]) {
			vs[i1][j1] = 0;
			Try(i1, j1);
			vs[i1][j1] = 1;
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
		nhap();
		res = 0;
		vs[1][1] = 0;
		Try(1, 1);
		cout << res << endl;
	}
	return 0;
}