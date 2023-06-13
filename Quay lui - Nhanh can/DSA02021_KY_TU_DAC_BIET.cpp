#include <bits/stdc++.h>
#pragma gcc optimize("Ofast")
#define endl '\n'
using namespace std;

using ll = long long;

ll sz;
char back_track(ll k, string s, ll n)
{
	if (k <= sz)
		return s[k];
	if (k <= n / 2)
		return back_track(k, s, n / 2);
	if (k == (n / 2) + 1)
		return back_track(k - 1, s, n / 2);
	if (k > (n / 2) + 1)
		return back_track(k - (n / 2) - 1, s, n / 2);
	return 'L';
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
	cin.ignore();
	while (t--)
	{
		string s;
		cin >> s;
		ll k;
		cin >> k;
		cin.ignore(1);
		ll n = s.size();
		sz = s.size();
		s = " " + s;
		while (n < k)
			n *= 2;
		cout << back_track(k, s, n) << endl;
	}
	return 0;
}