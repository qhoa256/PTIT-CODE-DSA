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
		int a[n + 1];
		int b[n + 1];
		for (int i = 1; i <= n; i++) {
			cin >> a[i];
			b[i] = a[i];
		}
		sort(b + 1, b + n + 1);
		int dau, val1, val2, cuoi;
		for (int i = 1; i <= n; i++) {
			if (a[i] != b[i]) {
				dau = i;
				val1 = a[i];
				val2 = b[i];
				break;
			}
		}
		for (int i = 1; i <= n; i++) {
			if (a[i] == val2) {
				cout << abs(i - dau) << endl;
				break;
			}
		}
	}
	return 0;
}