#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int n, k, a[1005], res = 0, S = 0;

void Try(int i, int sum, int cnt) {
	if (cnt == k && i == n + 1) {
		res++;
		return;
	}
	for (int j = i; j <= n; j++) {
		sum += a[j];
		if (sum == S / k) {
			Try(j + 1, 0, cnt + 1);
		}
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
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		S += a[i];
	}
	if (S % k) {
		cout << 0;
	} else {
		Try(1, 0, 0);
		cout << res;
	}
	return 0;
}