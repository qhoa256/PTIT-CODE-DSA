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
		int s, d;
		cin >> s >> d;
		if (s > 9 * d) {
			cout << -1;
		} else {
			int a[d];
			memset(a, 0, sizeof(a));
			s -= 1;
			for (int i = d - 1; i >= 0; i--) {
				if (s >= 9) {
					a[i] = 9;
					s -= 9;
				} else {
					a[i] = s;
					break;
				}
			}
			a[0] += 1;
			for (int i = 0; i < d; i++) {
				cout << a[i];
			}
		}
		cout << endl;
	}
	return 0;
}