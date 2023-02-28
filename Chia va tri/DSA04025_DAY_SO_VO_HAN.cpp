#include <bits/stdc++.h>

using namespace std;

using ll = long long;
const int mod = 1e9 + 7;

struct matrix {
	ll F[15][15];
	ll n;

	matrix operator * (matrix b) {
		matrix res;
		res.n = n;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				res.F[i][j] = 0;
				for (int k = 0; k < n; k++) {
					res.F[i][j] += (F[i][k] % mod) * (b.F[k][j] % mod);
					res.F[i][j] %= mod;
				}
			}
		}
		return res;
	}
};

matrix powMod(matrix a, ll n) {
	if (n == 1) return a;
	matrix res = powMod(a, n / 2);
	if (n % 2) return res * res * a;
	else return res * res;
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
		ll n;
		cin >> n;
		matrix fibo;
		fibo.n = 2;
		fibo.F[0][0] = fibo.F[0][1] = fibo.F[1][0] = 1;
		fibo.F[1][1] = 0;
		matrix res = powMod(fibo, n);
		cout << res.F[1][0] << endl;
	}
	return 0;
}