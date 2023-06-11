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
	int n;
	cin >> n;
	ll sum = 0;
	for (int i = 0; i < n; i++) {
		ll x;
		cin >> x;
		if (x > 0)sum += x * 2;
	}
	cout << sum << endl;
	return 0;
}