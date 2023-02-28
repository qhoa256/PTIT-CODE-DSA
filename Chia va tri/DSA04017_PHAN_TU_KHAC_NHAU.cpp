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
		int n;
		cin >> n;
		int a[n], b[n - 1];
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		for (int i = 0; i < n - 1; i++) {
			cin >> b[i];
		}
		int pos = n;
		for (int i = 0; i < n - 1; i++) {
			if (a[i] != b[i]) {
				pos = i + 1;
				break;
			}
		}
		cout << pos << endl;
	}
	return 0;
}