#include <bits/stdc++.h>

using namespace std;

using ll = long long;

ll t, n, k, F[93];

void Fibo() {
	F[0] = 0;
	F[1] = 1;
	for (int i = 2; i <= 92; i++) {
		F[i] = F[i - 1] + F[i - 2];
	}
}

ll Find(ll n, ll k) {
	if (n < 2) return n;
	if (k <= F[n]) return Find(n - 1, k);
	else return F[n - 1] + Find(n - 2, k - F[n]);
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
	Fibo();
	cin >> t;
	while (t--) {
		cin >> n >> k;
		cout << Find(n, k) << endl;
	}
	return 0;
}