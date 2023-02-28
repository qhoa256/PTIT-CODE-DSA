#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int t, n, k, a[1005], x[1005];

void Try(int i) {
	for (int j = x[i - 1] + 1; j <= n - k + i; j++) {
		x[i] = j;
		if (i == k) {
			for (int h = 1; h <= k; h++) {
				cout << a[x[h]] << " ";
			} cout << endl;
		} else Try(i + 1);
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
		Try(1);
	}
	return 0;
}