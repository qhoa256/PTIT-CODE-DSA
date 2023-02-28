#include <bits/stdc++.h>
using namespace std;

int a[1005], x[1005], t, n, s;
bool ok;
void Try(int i, int pos, int sum) {
	if (ok) return;
	for (int j = pos; j <= n; j++) {
		if (sum + a[j] <= s / 2) {
			if (sum + a[j] == s / 2) {
				ok = true;
				return;
			} else Try(i + 1, j + 1, sum + a[j]);
		}
	}
}
int main() {
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
		s = 0; ok = false;
		for (int i = 1; i <= n; i++) {
			cin >> a[i];
			s += a[i];
		}
		if (s % 2) cout << "NO\n";
		else
		{
			Try(1, 1, 0);
			if (ok) cout << "YES\n";
			else cout << "NO\n";
		}
	}
	return 0;
}