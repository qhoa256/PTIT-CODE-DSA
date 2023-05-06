#include <bits/stdc++.h>
#pragma gcc optimize("Ofast")
using namespace std;

using ll = long long;

int t, n, a[1005];

void solve() {
	map<int, int> mp;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		mp[a[i]]++;
	}
	int check = 1;
	for (int i = n; i >= 0; i--) {
		int dem = 0;
		for (int j = 0; j <= i; j++) dem += mp[j];
		if (n - mp[i] == i) {
			if (i <= n - dem && dem != 0  )	{
				cout << i << endl;
				check = 0;
				break;
			}
		}
		else {
			int dem2 = 0;
			for (int k = i + 1; k <= n; k++) if (mp[k] != 0 && k <= n - dem) dem2 = 1;
			if (i <= n - dem && dem != 0 && !dem2 )	{
				cout << i << endl;
				check = 0;
				break;
			}
		}
	}
	if (check) cout << "-1\n";
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
		solve();
	}
	return 0;
}