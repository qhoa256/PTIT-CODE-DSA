#include <bits/stdc++.h>
#pragma gcc optimize("Ofast")
using namespace std;

using ll = long long;

int t, n, k;

int solve() {
	int n, k;
	cin >> n >> k;
	string s[n + 1];
	int a[n + 1][k + 1];
	memset(a, 0, sizeof(a));
	for (int i = 0; i < n; i++) cin >> s[i];
	for (int i = 0; i < k; i++) {
		char res = s[0][i];
		for (int j = 0; j < n; j++) {
			if (s[j][i] != res ) a[j][i] = 1;
			if (i > 0 && a[j][i - 1] == 1) a[j][i] = 1;
		}
	}
	int dem = 0;
	for (int i = 0; i < n; i++) if (!a[i][k - 1]) dem++;
	return dem;
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
	cin >> t;
	while (t--) {
		cout << solve() << endl;
	}
	return 0;
}