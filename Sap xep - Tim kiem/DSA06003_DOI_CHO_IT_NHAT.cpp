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
		int a[n];
		for (int &x : a)
			cin >> x;
		int cnt = 0;
		for (int i = 0; i < n - 1; ++i) {
			int tmp = a[i], idx = 0;
			for (int j = i + 1; j < n; ++j) {
				if (a[j] < tmp) {
					tmp = a[j];
					idx = j;
				}
			}
			if (tmp < a[i]) {
				++cnt;
				swap(a[idx], a[i]);
			}
		}
		cout << cnt << "\n";
	}
	return 0;
}