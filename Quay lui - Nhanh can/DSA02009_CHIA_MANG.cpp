#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int t, n, k, s, ok, a[1005], used[1005];

void Try(int i, int pos, int sum, int cnt) {
	if (ok) return;
	if (cnt == k) {
		ok = 1;
		return;
	}
	for (int j = pos; j <= n; j++) {
		if (!used[j] && sum + a[j] <= s) {
			used[j] = 1;
			if (sum + a[j] == s) {
				Try(i + 1, 1, 0, cnt + 1);
			} else {
				Try(i + 1, j + 1, sum + a[j], cnt);
			}
			used[j] = 0;
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
		memset(used, 0, sizeof(used));
		s = 0;
		ok = 0;
		cin >> n >> k;
		for (int i = 1; i <= n; i++) {
			cin >> a[i];
			s += a[i];
		}
		if (s % k == 0) {
			s /= k;
			Try(1, 1, 0, 0);
			cout << ok << endl;
		} else {
			cout << 0 << endl;
		}
	}
	return 0;
}