#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const int mod = 1e9 + 7;

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
		ll n, k;
		cin >> n >> k;
		if (n < k) cout << 0 << endl;
		else {
			long ans = 1;
			for (int i = 0; i <= k - 1; i++) {
				ans *= (n - i);
				ans %= mod;
			}
			cout << ans << endl;
		}
	}
	return 0;
}