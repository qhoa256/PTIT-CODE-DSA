#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int t, n, a[1005];
bool check() {
	int cnt[15] = {0};
	for (int i = 0; i < n; i++) {
		cnt[a[i]]++;
	}
	for (int i = 1; i <= n; i++) {
		if (cnt[i] > 1) return false;
	}
	for (int i = 0; i < n - 1; i++) {
		if (abs(a[i] - a[i + 1]) == 1) return false;
	}
	return true;

}
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
			a[i] = i + 1;
		}
		do {
			if (check()) {
				for (int i = 0; i < n; i++) cout << a[i];
				cout << endl;
			}
		} while (next_permutation(a, a + n));
	}
	return 0;
}