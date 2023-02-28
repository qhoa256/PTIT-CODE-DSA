#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int t, a[1005][1005], d1[1005], d2[1005], col[1005];
int ans;

void nhap() {
	for (int i = 1; i <= 8; i++) {
		for (int j = 1; j <= 8; j++) {
			cin >> a[i][j];
		}
	}
}

void Try(int i, int sum) {
	for (int j = 1; j <= 8; j++) {
		if (!d1[i + j - 1] && !d2[i - j + 8] && !col[j]) {
			sum += a[i][j];
			col[j] = 1;
			d1[i + j - 1] = 1;
			d2[i - j + 8] = 1;
			if (i == 8) {
				ans = max(ans, sum);
			} else Try(i + 1, sum);
			sum -= a[i][j];
			col[j] = 0;
			d1[i + j - 1] = 0;
			d2[i - j + 8] = 0;
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
		ans = -1e9;
		nhap();
		Try(1, 0);
		cout << ans << endl;
		memset(d1, 0, sizeof(d1));
		memset(d2, 0, sizeof(d2));
		memset(col, 0, sizeof(col));
	}
	return 0;
}