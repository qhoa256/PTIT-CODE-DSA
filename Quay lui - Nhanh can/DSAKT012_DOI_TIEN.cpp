#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int n, k, a[1005], res = 1e9;

void Try(int i, int pos, int sum) {
	if (i >= res) return;
	for (int j = pos; j <= n; j++) {
		if (sum + a[j] <= k) {
			if (sum + a[j] == k) {
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
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	Try(1, 1, 0);
	if (res == 1e9) cout << -1; else cout << res;
	return 0;
}