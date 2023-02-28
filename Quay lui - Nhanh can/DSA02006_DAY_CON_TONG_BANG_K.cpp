#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int t, n, k, x[1005], a[1005];
bool check;
void Try(int i, int pos, int sum) {
	for (int j = pos; j <= n; j++) {
		x[i] = a[j];
		if (sum + a[j] <= k) {
			if (sum + a[j] == k) {
				check = true;
				cout << "[";
				for (int k = 1; k <= i; k++) {
					cout << x[k];
					if (k != i) cout << " ";
				}
				cout << "] ";
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
		cin >> n >> k;
		for (int i = 1; i <= n; i++) {
			cin >> a[i];
		}
		sort(a + 1, a + n + 1);
		check = false;
		Try(1, 1, 0);
		if (!check) cout << "-1";
		cout << endl;
	}
	return 0;
}