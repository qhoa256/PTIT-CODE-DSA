#include <bits/stdc++.h>
#pragma gcc optimize("Ofast")
#define endl '\n'
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
		ll a[n], b[n];
		for (int i = 0; i < n; ++i) {
			cin >> a[i];
			b[i] = a[i];
		}
		sort(a, a + n);
		int ans = 0;
		for (int i = 0; i < n; ++i) {
			if (b[i] == a[0]) {
				ans = i;
				break;
			}
		}
		cout << ans << "\n";
	}
	return 0;
}