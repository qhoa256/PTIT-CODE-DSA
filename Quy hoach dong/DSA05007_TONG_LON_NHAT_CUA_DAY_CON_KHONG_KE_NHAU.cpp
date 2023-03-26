#include <bits/stdc++.h>

using namespace std;

using ll = long long;

ll sum[1000005];

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
		memset(sum, 0, sizeof(sum));
		int n;
		cin >> n;
		int a[n + 1];
		for (int i = 1; i <= n; i++) {
			cin >> a[i];
		}
		sum[1] = a[1];
		for (int i = 2; i <= n; i++) {
			sum[i] = max(sum[i - 1], sum[i - 2] + a[i]);
		}
		cout << sum[n] << endl;
	}
	return 0;
}