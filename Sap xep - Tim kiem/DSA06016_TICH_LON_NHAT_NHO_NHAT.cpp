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
		int n, m;
		cin >> n >> m;
		ll a[n], b[m];
		for (auto &x : a) cin >> x;
		for (auto &x : b) cin >> x;
		sort(a, a + n);
		sort(b, b + m);
		cout << a[n - 1]*b[0] << endl;
	}
	return 0;
}