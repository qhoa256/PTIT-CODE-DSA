#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int n, k, x[1005];
string s[1005];
int res = 1e9;

int solve() {
	int minx = 1e9, maxx = -1e9;
	for (int i = 0; i < n; i++) {
		string tmp = "";
		for (int j = 0; j < k; j++) {
			tmp += s[i][x[j]];
		}
		minx = min(minx, stoi(tmp));
		maxx = max(maxx, stoi(tmp));
	}
	return maxx - minx;
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
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> s[i];
	}
	for (int i = 0; i < k; i++) {
		x[i] = i;
	}
	do {
		res = min(res, solve());
	} while (next_permutation(x, x + k));
	cout << res;
	return 0;
}