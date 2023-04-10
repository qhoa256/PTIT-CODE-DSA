#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int t, n, k, s, a[100005], F[1005], ok;
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
		ok = 0;
		cin >> n >> k >> s;
		for (int i = 1; i <= n; i++) {
			cin >> a[i];
		}
		for (int i = 1; i <= n; i++) {
			if (i == 1) {
				F[i] = a[i];
			} else {
				F[i] = F[i - 1] + a[i];
			}
		}
		int pos = 1e9;
		for (int i = 1; i <= min(n, s); i++) {
			if (F[s] - F[i] + a[i] <= k) {
				ok = 1;
				cout << i << endl;
				break;
			}
		}
		if (!ok)cout << -1 << endl;
	}
	return 0;
}