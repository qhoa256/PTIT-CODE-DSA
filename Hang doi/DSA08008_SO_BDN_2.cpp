#include <bits/stdc++.h>
#pragma gcc optimize("Ofast")
using namespace std;

using ll = long long;

ll t, n;

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
		cin >> n;
		queue<ll>q;
		q.push(1);
		while (1) {
			ll x = q.front();
			q.pop();
			if (x % n == 0) {
				cout << x << endl;
				break;
			}
			q.push(x * 10);
			q.push(x * 10 + 1ll * 1);
		}
	}
	return 0;
}