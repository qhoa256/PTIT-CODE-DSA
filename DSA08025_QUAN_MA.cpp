#include <bits/stdc++.h>
#pragma gcc optimize("Ofast")
using namespace std;

using ll = long long;

int kx[8] = { -1, -2, -2, -1, 1, 2, 2, 1};
int ky[8] = { -2, -1, 1, 2, 2, 1, -1, -2};
int dp[9][9];
int getNum(char x) {
	if (x == 'a') return 1;
	else if (x == 'b') return 2;
	else if (x == 'c') return 3;
	else if (x == 'd') return 4;
	else if (x == 'e') return 5;
	else if (x == 'f') return 6;
	else if (x == 'g') return 7;
	else return 8;
}

void BFS(int s, int t, int e, int n) {
	queue<pair<int, int>>q;
	q.push({s, t});
	dp[s][t] = 0;
	while (!q.empty()) {
		auto x = q.front();
		q.pop();
		int i = x.first, j = x.second;
		if (i == e && j == n) return;
		for (int k = 0; k < 8; k++) {
			int i1 = i + kx[k];
			int j1 = j + ky[k];
			if (i1 >= 1 && i1 <= 8 && j1 >= 1 && j1 <= 8 && dp[i1][j1] == 0) {
				dp[i1][j1] = dp[i][j] + 1;
				q.push({i1, j1});
			}
		}
	}
	return;
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
	int t;
	cin >> t;
	while (t--) {
		string s1, s2;
		cin >> s1 >> s2;
		for (int i = 1; i <= 8; i++) {
			for (int j = 1; j <= 8; j++) {
				dp[i][j] = 0;
			}
		}
		BFS(getNum(s1[1]), s1[0] - '0', getNum(s2[1]), s2[0] - '0');
		cout << dp[getNum(s2[1])][s2[0] - '0'] << endl;
	}
	return 0;
}