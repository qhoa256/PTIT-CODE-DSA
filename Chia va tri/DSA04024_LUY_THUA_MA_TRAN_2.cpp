#include <bits/stdc++.h>

using namespace std;

using ll = long long;
const int mod = 1e9 + 7;

struct matrix {
	ll a[15][15];
	ll n;

	matrix operator * (matrix b) {
		matrix res;
		res.n = n;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				res.a[i][j] = 0;
				for (int k = 0; k < n; k++) {
					res.a[i][j] += (a[i][k] % mod) * (b.a[k][j] % mod);
					res.a[i][j] %= mod;
				}
			}
		}
		return res;
	}
};

matrix powMod2(matrix a, ll k) {
	if (k == 1) return a;
	matrix res = powMod2(a, k / 2);
	if (k % 2) return res * res * a;
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
		ll n, k;
		cin >> n >> k;
		matrix F;
		F.n = n;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cin >> F.a[i][j];
			}
		}
		matrix res = powMod2(F, k);
		ll sum = 0;
		for (int i = 0; i < n; i++) {
			sum += res.a[i][n - 1];
			sum %= mod;
		}
		cout << sum << endl;
	}
	return 0;
}