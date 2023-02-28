#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int floor(ll a[], int l, int r, int x) {
	if (l > r) return -1;
	int m = (l + r) / 2;
	if (a[m] <= x) {
		int res = floor(a, m + 1, r, x);
		if (res != -1) return res; else return m + 1;
	} else {
		return floor(a, l, m - 1, x);
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
	int t;
	cin >> t;
	while (t--) {
		ll n, x;
		cin >> n >> x;
		ll a[n];
		for (auto &x : a) cin >> x;
		cout << floor(a, 0, n - 1, x) << endl;
	}
	return 0;
}