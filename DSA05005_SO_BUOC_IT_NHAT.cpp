#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int t, n, a[1000005], F[1000005];
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> t;
	while (t--) {
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		for (int i = 0; i < n; i++) {
			F[i] = 1;
			for (int j = 0; j < i; j++) {
				if (a[j] <= a[i])
					F[i] = max(F[i], F[j] + 1);
			}
		}
		cout << n - *max_element(F, F + n) << endl;
	}
	return 0;
}