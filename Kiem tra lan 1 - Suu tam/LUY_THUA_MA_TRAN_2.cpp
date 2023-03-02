#include <bits/stdc++.h>

using namespace std;

using ll = long long;
const int mod = 1e9 + 7;
ll t, n, k;
struct matrix {
	ll a[15][15];
	int n;
	matrix operator * (matrix b) {
		matrix res;
		res.n = n;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				res.a[i][j] = 0;
				for (int k = 1; k <= n; k++) {
					res.a[i][j] += (a[i][k] % mod) * (b.a[k][j] % mod);
					res.a[i][j] %= mod;
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
	cin >> t;
	while (t--) {
		cin >> n >> k;
		matrix h;
		h.n = n;
		for (ll i = 1; i <= n; i++) {
			for (ll j = 1; j <= n; j++) {
				cin >> h.a[i][j];
			}
		}
		matrix res = powMod(h, k);
		ll sum = 0;
		for (ll i = 1; i <= n; i++) {
			sum += res.a[i][i];
			sum %= mod;
		}
		cout << sum << endl;
	}
	return 0;
}