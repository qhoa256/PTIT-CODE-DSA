#include <bits/stdc++.h>
#pragma gcc optimize("Ofast")
#define endl '\n'
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
	int n, m;
	cin >> n >> m;
	int a[n];
	for (int i = 0; i < n; i++) {
		a[i] = i + 1;
	}
	int idx = 1;
	do {
		if (idx % m == 0) {
			for (auto &x : a) cout << x << " ";
			cout << endl;
		}
		idx++;
	} while (next_permutation(a, a + n));
	return 0;
}