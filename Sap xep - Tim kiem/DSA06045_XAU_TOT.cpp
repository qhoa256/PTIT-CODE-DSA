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
	ll n;
	cin >> n;
	cin.ignore(1);
	string s;
	cin >> s;
	ll cnt = 1, res = n * (n - 1) >> 1;
	vector<ll> v;
	for (ll i = 1; i < n; i++)
	{
		if (s[i] == s[i - 1])
			cnt++;
		else
		{
			v.push_back(cnt);
			cnt = 1;
		}
	}
	v.push_back(cnt);
	for (ll i = 1; i < v.size(); i++)
	{
		res -= (v[i] + v[i - 1] - 1);
	}
	cout << res << endl;
	return 0;
}