#include <bits/stdc++.h>

using namespace std;

using ll = long long;

char Find(ll n, ll k) {
	if (k % 2) return 'A';
	if (k == (ll)pow(2, n - 1)) return ('A' + n - 1);
	if (k < (ll)pow(2, n - 1)) return Find(n - 1, k);
	else return Find(n - 1, k - (ll)pow(2, n - 1));
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
		cout << Find(n, k) << endl;
	}
	return 0;
}