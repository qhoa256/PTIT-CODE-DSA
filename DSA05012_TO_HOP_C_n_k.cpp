#include <bits/stdc++.h>

using namespace std;

using ll = long long;

ll F[1005][1005];
const int mod = 1e9 + 7;
void nCk() {
	for (int i = 0; i <= 1000; i++) {
		for (int j = 0; j <= i; j++) {
			if (j == 0 || j == i) F[i][j] = 1;
			else {
				F[i][j] = F[i - 1][j] % mod + F[i - 1][j - 1] % mod;
				F[i][j] %= mod;
			}

		}
	}
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
	nCk();
	int t;
	cin >> t;
	while (t--) {
		int n, k;
		cin >> n >> k;
		cout << F[n][k] << endl;
	}
	return 0;
}