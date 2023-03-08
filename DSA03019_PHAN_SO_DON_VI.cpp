#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int t;

void qlui(ll tu, ll mau) {
	if (mau % tu == 0) {
		cout << 1 << "/" << mau / tu << endl;
		return;
	}
	ll x = mau / tu + 1;
	cout << 1 << "/" << x << " + ";
	ll maumoi = mau * x;
	ll tumoi = tu * x - mau;
	qlui(tumoi, maumoi);
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
		ll tu, mau;
		cin >> tu >> mau;
		qlui(tu, mau);
	}
	return 0;
}