#include <bits/stdc++.h>
#pragma gcc optimize("Ofast")
#define endl '\n'
using namespace std;

using ll = long long;

ll k;
ll decimal(string s)
{
	ll res = 0;
	for (ll i = 0; i < s.size(); i++)
	{
		res = res * k + (s[i] - '0');
	}
	return res;
}
void convert(ll res)
{
	stack<ll> st;
	while (res)
	{
		ll r = res % k;
		st.push(r);
		res /= k;
	}
	while (st.size())
	{
		cout << st.top();
		st.pop();
	}
	cout << endl;
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
	ll t;
	cin >> t;
	while (t--)
	{
		k = 2;
		string s1, s2;
		cin >> s1 >> s2;
		ll res1 = decimal(s1);
		ll res2 = decimal(s2);
		cout << res1 * res2 << endl;
	}
	return 0;
}