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
		int n, s;
		cin >> n >> s;
		int a[n];
		for (auto &x : a) cin >> x;
		bool F[100005];
		memset(F, false, sizeof(F));
		F[0] = true;
		for (int i = 0; i < n; i++) {
			for (int j = s; j >= a[i]; j--) {
				if (F[j - a[i]]) {
					F[j] = true;
				}
			}
		}
		if (F[s]) cout << "YES\n";
		else cout << "NO\n";
	}
	return 0;
}