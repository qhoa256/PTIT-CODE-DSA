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


matrix powMod(matrix a, int k) {
	if (k == 1) return a;
	matrix res = powMod(a, k / 2);
	if (k % 2) return res * res * a; else return res * res;
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
		int n;
		cin >> n;
		matrix F;
		F.n = 2;
		F.a[0][0] = F.a[0][1] = F.a[1][0] = 1;
		F.a[1][1] = 0;
		matrix res = powMod(F, n);
		cout << res.a[0][1] << endl;
	}
	return 0;
}