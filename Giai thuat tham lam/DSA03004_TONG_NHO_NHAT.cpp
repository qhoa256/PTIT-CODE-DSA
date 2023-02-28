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
		int n;
		cin >> n;
		int a[n];
		for (auto &x : a) cin >> x;
		sort(a, a + n);
		ll sum1 = 0, sum2 = 0;
		for (int i = 0; i < n; i++) {
			if (i % 2 == 0) sum1 = sum1 * 10 + a[i];
			if (i % 2 == 1) sum2 = sum2 * 10 + a[i];
		}
		cout << sum1 + sum2 << endl;
	}
	return 0;
}