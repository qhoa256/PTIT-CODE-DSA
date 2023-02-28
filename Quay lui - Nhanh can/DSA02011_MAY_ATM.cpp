#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int t, n, s, a[1005], res;

void Try(int i, int pos, int sum) {
	if (i >= res) return;
	for (int j = pos; j <= n; j++) {
		if (sum + a[j] <= s) {
			if (sum + a[j] == s) {
				res = min(res, i);
			} else Try(i + 1, j + 1, sum + a[j]);
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
		cin >> n >> s;
		for (int i = 1; i <= n; i++) {
			cin >> a[i];
		}
		res = 1e9;
		Try(1,1,0);
		if (res == 1e9) cout << -1 << endl; else cout << res << endl;
	}
	return 0;
}