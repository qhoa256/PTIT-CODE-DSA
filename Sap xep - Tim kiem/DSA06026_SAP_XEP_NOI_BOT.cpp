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
	int n;
	cin >> n;
	int a[n + 1];
	a[0] = 0;
	int ok;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for (int i = 1; i <= n - 1; i++) {
		for (int j = 1; j <= n - i; j++) {
			if (a[j] > a[j + 1]) {
				swap(a[j], a[j + 1]);
			}
		}
		ok = 1;
		cout << "Buoc " << i << ": ";
		for (int k = 1; k <= n; k++) {
			if (a[k] < a[k - 1]) ok = 0;
			cout << a[k] << " ";
		}
		if (ok) break;
		cout << endl;
	}
	return 0;
}