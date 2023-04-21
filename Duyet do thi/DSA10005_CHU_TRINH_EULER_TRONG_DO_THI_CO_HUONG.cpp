#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int t, n, m;
int degIn[1005];
int degOut[1005];


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
		cin >> n >> m;
		for (int i = 0; i < m; i++) {
			int x, y;
			cin >> x >> y;
			degOut[x]++;
			degIn[y]++;
		}
		int ok = 1;
		for (int i = 1; i <= n; i++) {
			if (degIn[i] != degOut[i]) {
				ok = 0;
				break;
			}
		}
		cout << ok << endl;
		memset(degOut, 0, sizeof(degOut));
		memset(degIn, 0, sizeof(degIn));
	}
	return 0;
}