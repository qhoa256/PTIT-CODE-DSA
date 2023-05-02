#include <bits/stdc++.h>
#pragma gcc optimize("Ofast")
using namespace std;

using ll = long long;

int t, n;
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
		int ok = 0;
		cin >> n;
		int a[n];
		for (int i = 0; i < n; i++) {
			a[i] = i + 1;
		}
		int sum = 0;
		for (auto &x : a) {
			sum += x;
		}
		for (int i = 1; i <= n; i++) {
			for (int j = i + 1; j <= n; j++) {
				
			}
		}
	}
	return 0;
}