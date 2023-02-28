#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int n, k, s;
int res;
int X[1005];
void Try(int i, int sum) {
	for (int j = X[i - 1] + 1; j <= n - k + i; j++) {
		X[i] = j;
		if (sum + j <= s && i <= k) {
			if (sum + j == s && i == k) {
				res++;
			} else Try(i + 1, sum + j);
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
	while (1) {
		cin >> n >> k >> s;
		if (n == 0 && k == 0 && s == 0) break;
		res = 0;
		Try(1, 0);
		cout << res << endl;
	}
	return 0;
}