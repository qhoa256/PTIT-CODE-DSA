#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int t, n, x, a[1005], X[1005], ok;

void Try(int i, int pos, int sum) {
	for (int j = pos; j <= n; j++) {
		if (sum + a[j] <= x) {
			X[i] = a[j];
			if (sum + a[j] == x) {
				ok = 1;
				cout << "[";
				for (int k = 1; k <= i; k++) {
					cout << X[k];
					if (k != i) cout << " ";
				}
				cout << "]";
			} else Try(i + 1, j, sum + a[j]);
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
		ok = 0;
		cin >> n >> x;
		for (int i = 1; i <= n; i++) {
			cin >> a[i];
		}
		Try(1, 1, 0);
		if (!ok) cout << -1;
		cout << endl;
	}
	return 0;
}