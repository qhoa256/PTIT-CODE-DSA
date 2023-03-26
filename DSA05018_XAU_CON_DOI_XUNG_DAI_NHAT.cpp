#include <bits/stdc++.h>

using namespace std;

using ll = long long;

bool F[1005][1005];

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
		int ans = -1e9;
		memset(F, false, sizeof(F));
		string s;
		cin >> s;
		int n = s.size();
		for (int i = n - 1; i >= 0; i--) {
			for (int j = i; j < n; j++) {
				if (i == j) F[i][j] = true;
				else if (s[i] == s[j]) {
					if (j - i == 1) F[i][j] = true;
					else F[i][j] = F[i + 1][j - 1];
				}
				if (F[i][j]) ans = max(ans, j - i + 1);
			}
		}
		cout << ans << endl;
	}
	return 0;
}