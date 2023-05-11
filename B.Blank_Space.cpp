#include <bits/stdc++.h>
#pragma gcc optimize("Ofast")
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
		for (auto &x : a) {
			cin >> x;
		}
		int res = 0;
		int cnt = 0;
		for (auto &x : a) {
			if (x == 0) {
				cnt++;
			} else {
				res = max(res, cnt);
				cnt = 0;
			}
		}
		if (a[n - 1] == 0) {
			res = max(res, cnt);
		}
		cout << res << endl;
	}
	return 0;
}