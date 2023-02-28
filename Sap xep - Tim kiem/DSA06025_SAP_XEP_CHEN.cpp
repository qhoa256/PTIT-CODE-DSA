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
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	cout << "Buoc 0: " << a[1] << endl;
	for (int i = 2; i <= n; i++) {
		int pos = i - 1, val = a[i];
		while (i >= 1 && val < a[pos]) {
			a[pos + 1] = a[pos];
			--pos;
		}
		a[pos + 1] = val;
		cout << "Buoc " << i - 1 << ": ";
		for (int j = 1; j <= i; j++) {
			cout << a[j] << " ";
		}
		cout << endl;
	}
	return 0;
}