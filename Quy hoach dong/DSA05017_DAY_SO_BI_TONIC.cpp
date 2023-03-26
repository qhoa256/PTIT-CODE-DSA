#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int inc[1000005];
int de[1000005];
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

		for (int i = 1; i <= n; i++) {
			cin >> a[i];
		}
		memset(inc, 0, sizeof(inc));
		for (int i = 1; i <= n; i++) {
			inc[i] = a[i];
			for (int j = 1; j <= i; j++) {
				if (a[i] > a[j]) {
					inc[i] = max(inc[i], inc[j] + a[i]);
				}
			}
		}
		memset(de, 0, sizeof(de));
		for (int i = n; i >= 1; i--) {
			de[i] = a[i];
			for (int j = n; j >= i; j--) {
				if (a[i] > a[j]) {
					de[i] = max(de[i], de[j] + a[i]);
				}
			}
		}
		int ans = 0;
		for (int i = 1; i <= n; i++) {
			ans = max(ans, inc[i] + de[i] - a[i]);
		}
		cout << ans << endl;
	}
	return 0;
}