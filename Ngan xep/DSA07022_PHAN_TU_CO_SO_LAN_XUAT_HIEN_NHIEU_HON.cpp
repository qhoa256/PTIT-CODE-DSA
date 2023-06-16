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
	ll t;
	cin >> t;
	while (t--)
	{
		ll n;
		cin >> n;
		ll a[n], c[n];
		map<ll, ll> mp;
		for (auto &x : a)
		{
			cin >> x;
			mp[x]++;
		}
		stack<ll> st;
		for (ll i = 0; i < n; i++)
		{
			if (st.empty())
				st.push(i);
			else
			{
				if (mp[a[i]] <= mp[a[st.top()]])
					st.push(i);
				else
				{
					while (!st.empty() && mp[a[i]] > mp[a[st.top()]])
					{
						ll top = st.top();
						st.pop();
						c[top] = a[i];
					}
					st.push(i);
				}
			}
		}
		while (!st.empty())
		{
			ll top = st.top();
			st.pop();
			c[top] = -1;
		}
		for (ll i = 0; i < n; i++)
			if (c[i] != -1)
				cout << c[i] << " ";
			else
				cout << -1 << " ";
		cout << endl;
	}
	return 0;
}