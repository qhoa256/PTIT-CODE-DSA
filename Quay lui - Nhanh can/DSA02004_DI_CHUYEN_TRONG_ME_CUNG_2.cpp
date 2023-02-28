#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int t, ok, n, a[1005][1005];
string s = "DLRU";
pair<int, int>p[4] = {{1, 0}, {0, -1}, {0, 1}, { -1, 0}};
string res;

void nhap() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> a[i][j];
		}
	}
}
void Try(int i, int j) {
	if (i == n && j == n) {
		ok = 1;
		cout << res << " ";
	}
	for (int k = 0; k < 4; k++) {
		int i1 = i + p[k].first;
		int j1 = j + p[k].second;
		if (i1 >= 1 && i1 <= n && j1 >= 1 && j1 <= n && a[i1][j1]) {
			res += s[k];
			a[i1][j1] = 0;
			Try(i1, j1);
			a[i1][j1] = 1;
			res.pop_back();
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
		nhap();
		ok = 0;
		if (a[1][1]) {
			a[1][1] = 0;
			Try(1, 1);
		}
		if (!ok) cout << -1;
		cout << endl;
	}
	return 0;
}