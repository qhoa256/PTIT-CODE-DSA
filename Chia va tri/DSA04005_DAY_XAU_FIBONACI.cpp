#include <bits/stdc++.h>

using namespace std;

using ll = long long;

ll F[93];

void init() {
	F[0] = 0;
	F[1] = 1;
	for (int i = 2; i <= 92; i++) {
		F[i] = F[i - 1] + F[i - 2];
	}
}

char Find(ll n, ll k) {
	if (n == 1) return 'A';
	if (n == 2) return 'B';
	if (k <= F[n - 2]) {
		return Find(n - 2, k);
	} else {
		return Find(n - 1, k - F[n - 2]);
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
	init();
	int t;
	cin >> t;
	while (t--) {
		ll n, k;
		cin >> n >> k;
		cout << Find(n, k) << endl;
	}
	return 0;
}