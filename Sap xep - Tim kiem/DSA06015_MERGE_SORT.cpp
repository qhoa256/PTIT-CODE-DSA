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
	int t;
	cin >> t;
	while (t--)
	{
		ll n; cin >> n;
		ll a[n];
		for (auto &x : a) cin >> x;
		sort(a, a + n);
		for (auto x : a) cout << x << " ";
		cout << endl;
	}
	return 0;
}