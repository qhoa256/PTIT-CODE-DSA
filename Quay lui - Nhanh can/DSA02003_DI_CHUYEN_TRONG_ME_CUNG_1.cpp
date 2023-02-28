#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int n, ok, a[1005][1005];
pair<int, int>path[2] = {{1, 0}, {0, 1}};
string s = "DR";
string res;

void Try(int i, int j) {
	if (i == n && j == n) {
		ok = 1;
		cout << res << " ";
	}
	for (int k = 0; k < 2; k++) {
		int i1 = i + path[k].first;
		int j1 = j + path[k].second;
		if (i1 >= 1 && i1 <= n && j1 >= 1 && j1 <= n && a[i1][j1]) {
			a[i1][j1] = 0;
			res += s[k];
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
	int t;
	cin >> t;
	while (t--) {
		cin >> n;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				cin >> a[i][j];
			}
		}
		res = "";
		ok = 0;
		if (a[1][1]) {
			a[1][1] = 0;
			Try(1, 1);
		}
		if (!ok) cout << -1;
		cout << endl;
		memset(a, 0, sizeof(a));
	}
	return 0;
}