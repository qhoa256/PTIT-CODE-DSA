#include <bits/stdc++.h>
#pragma gcc optimize("Ofast")
#define endl '\n'
using namespace std;

using ll = long long;

ll prime[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31}, n, ans = (ll)1e18;
void back_track(ll i, ll k, ll x)
{
	if (x > n)
		return;
	if (x == n)
		ans = min(ans, k);
	for (ll j = 1;; j++)
	{
		if (k * prime[i] > ans)
			break;
		k *= prime[i];
		back_track(i + 1, k, x * (j + 1));
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
	int t;
	cin >> t;
	while (t--) {
		cin >> n;
		ans = 1e18;
		back_track(0, 1, 1);
		cout << ans << endl;
	}
	return 0;
}