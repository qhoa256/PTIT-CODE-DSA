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
	int n, k;
	cin >> n >> k;
	int a[n];
	int res = 1;
	for (auto &x : a) cin >> x;
	sort(a, a + n);
	for (int i = 1; i < n; i++) {
		if (a[i] - a[i - 1] > k) res++;
	}
	cout << res;
	return 0;
}