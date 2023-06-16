#include <bits/stdc++.h>
#pragma gcc optimize("Ofast")
#define endl '\n'
using namespace std;

using ll = long long;

void solve(ll a[], ll n)
{
	ll res = 0;
	stack<ll> st;
	for (ll i = 0; i < n; i++)
	{
		if (st.empty())
			st.push(i);
		else
		{
			if (a[i] >= a[st.top()])
				st.push(i);
			else
			{
				ll cnt = 0;
				while (st.size() && a[i] < a[st.top()])
				{
					ll top = st.top();
					st.pop();
					ll dem;
					if (!st.size())
						dem = i;
					else
						dem = i - st.top() - 1;
					if (a[top] <= dem)
						res = max(res, min(a[top], dem));
				}
				st.push(i);
			}
		}
	}
	while (st.size())
	{
		ll top = st.top();
		st.pop();
		ll dem;
		if (!st.size())
			dem = n;
		else
			dem = n - st.top() - 1;
		if (a[top] <= dem)
			res = max(res, min(a[top], dem));
	}
	cout << res << endl;
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
	while (t--)
	{
		ll n;
		cin >> n;
		ll a[n];
		for (auto &x : a)
			cin >> x;
		solve(a, n);
	}
	return 0;
}