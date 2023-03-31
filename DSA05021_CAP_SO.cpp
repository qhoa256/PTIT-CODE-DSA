#include <bits/stdc++.h>

using namespace std;

using ll = long long;

//Sort theo vi tri cuoi va day con tang dai nhat
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
		int dp[1005];
		int ans = 1;
		for (int i = 0; i < n; i++) {
			dp[i] = 1;
			for (int j = 0; j < i; j++) {
				if (p[j].second < p[i].first) {
					dp[i] = max(dp[i], dp[j] + 1);
				}
			}
			ans = max(ans, dp[i]);
		}
		cout << ans << endl;
	}
	return 0;
}