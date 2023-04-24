#include <bits/stdc++.h>
#pragma gcc optimize("Ofast")
using namespace std;

using ll = long long;

ll t, n;
vector<ll>v;

void init() {
	queue<ll>q;
	q.push(1);
	while (1) {
		ll x = q.front();
		q.pop();
		if (x >= 1e18) break;
		v.push_back(x);
		q.push(x * 10);
		q.push(x * 10 + 1ll * 1);
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
	cin >> t;
	while (t--) {
		cin >> n;
		ll cnt = 0;
		for (ll i = 0; i < v.size(); i++) {
			if (v[i] <= n) cnt++;
			if (v[i] > n) break;
		}
		cout << cnt << endl;
	}
	return 0;
}