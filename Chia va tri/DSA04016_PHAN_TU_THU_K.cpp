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
		int m, n, k;
		cin >> m >> n >> k;
		vector<int>v;
		for (int i = 0; i < m; i++) {
			int x;
			cin >> x;
			v.push_back(x);
		}
		for (int i = 0; i < n; i++) {
			int x;
			cin >> x;
			v.push_back(x);
		}
		sort(v.begin(), v.end());
		cout << v[k - 1] << endl;
	}
	return 0;
}