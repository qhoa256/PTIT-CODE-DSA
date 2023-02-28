#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int t, n, ans = 0, d1[1005], d2[1005], col[1005], Q[1005];

void Try(int i) {
	for (int j = 1; j <= n; j++) {
		if (!d1[i + j - 1] && !d2[i - j + n] && !col[j]) {
			Q[i] = j;
			d1[i + j - 1] = 1;
			d2[i - j + n] = 1;
			col[j] = 1;
			if (i == n) {
				ans++;
			} else Try(i + 1);
			d1[i + j - 1] = 0;
			d2[i - j + n] = 0;
			col[j] = 0;
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
		cin >> n;
		ans = 0;
		Try(1);
		cout << ans << endl;
		memset(d1, 0, sizeof(d1));
		memset(d2, 0, sizeof(d2));
		memset(col, 0, sizeof(col));
	}
	return 0;
}