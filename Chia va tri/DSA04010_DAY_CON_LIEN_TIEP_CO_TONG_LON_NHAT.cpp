#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int n;
int crossSum(int a[], int l, int m, int r) {
	int left = 0, right = 0, max_left = 0, max_right = 0;
	for (int i = m - 1; i >= 0; i--) {
		left += a[i];
		max_left = max(max_left, left);
	}
	for (int i = m; i < n; i++) {
		right += a[i];
		max_right = max(max_right, right);
	}
	return max_left + max_right;
}
int maxSubArray(int a[], int l, int r) {
	if (l > r) return 0;
	if (l == r) return a[l];
	int m = (l + r) / 2;
	return max({maxSubArray(a, l, m), maxSubArray(a, m + 1, r), crossSum(a, l, m, r)});
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
		cin >> n;
		int a[n];
		for (auto &x : a) cin >> x;
		cout << maxSubArray(a, 0, n - 1) << endl;
	}
	return 0;
}