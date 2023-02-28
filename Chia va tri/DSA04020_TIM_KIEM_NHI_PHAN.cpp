#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int pos;

bool b_search(int a[], int l, int r, int k) {
	while (l <= r) {
		int m = (l + r) / 2;
		if (a[m] == k) {
			pos = m;
			return true;
		} else if (a[m] < k) {
			l = m + 1;
		} else {
			r = m - 1;
		}
	}
	return false;
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
		int n, k;
		cin >> n >> k;
		int a[n + 1];
		for (int i = 1; i <= n; i++) cin >> a[i];
		pos = -1;
		if (!b_search(a, 1, n, k)) cout << "NO\n"; else cout << pos << endl;
	}
	return 0;
}