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
		pair<int, int>p[n];
		for (int i = 0; i < n; i++) {
			cin >> p[i].first >> p[i].second;
		}
		sort(p, p + n, [](pair<int, int>a, pair<int, int>b)->bool{
			return a.second < b.second;
		});
		int tmp = p[0].second;
		int res = 1;
		for (int i = 1; i < n; i++) {
			if (p[i].first >= tmp) {
				res++;
				tmp = p[i].second;
			}
		}
		cout << res << endl;
	}
	return 0;
}