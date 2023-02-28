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
		int n, m, s;
		cin >> n >> s >> m;
		int ngay = s - s / 7;
		if (ngay * n < s * m) {
			cout << -1;
		} else {
			int res = m * s / n;
			if ((m * s) % n != 0) res += 1;
			cout << res;
		}
		cout << endl;
	}
	return 0;
}