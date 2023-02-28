#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	while (t--) {
		int n, k;
		cin >> n >> k;
		int a[n];
		for (auto &x : a) cin >> x;
		sort(a, a + n);
		int sum1 = 0, sum2 = 0;
		for (int i = 0; i < min(k, n - k); i++) {
			sum1 += a[i];
		}
		for (int i = min(k, n - k); i < n; i++) {
			sum2 += a[i];
		}
		cout << sum2 - sum1 << endl;
	}
	return 0;
}