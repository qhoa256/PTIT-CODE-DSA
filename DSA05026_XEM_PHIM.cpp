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
	int c, n;
	cin >> c >> n;
	int a[n];
	int sum = 0;
	for (auto &x : a) {
		cin >> x;
		sum += x;
	}
	bool F[sum + 1];
	memset(F, false, sizeof(F));
	F[0] = true;
	for (int i = 0; i < n; i++) {
		for (int j = sum; j >= a[i]; j--) {
			if (F[j - a[i]]) {
				F[j] = true;
			}
		}
	}
	for (int i = c; i >= 0; i--) {
		if (F[i]) {
			cout << i;
			break;
		}
	}
	return 0;
}