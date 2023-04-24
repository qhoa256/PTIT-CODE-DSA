#include <bits/stdc++.h>
#pragma gcc optimize("Ofast")
using namespace std;

using ll = long long;

int a[9] = {0, 1, 2, 3, 4, 5, 6, 7, 8};
int kx[8] = { -1, -2, -2, -1, 1, 2, 2, 1};
int ky[8] = { -2, -1, 1, 2, 2, 1, -1, -2};
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
		string s1, s2;
		cin >> s1 >> s2;
		int dp[9][9];
		for (int i = 1; i <= 9; i++) {
			for (int j = 1; j <= 9; j++) {
				dp[i][j] = 1e9;
			}
		}
		queue<pair<int, int>>q;
		q.push({a[s1[0]], s1[1] - '0'});
		dp[a[s1[]]][1]
	}
	return 0;
}