#include <bits/stdc++.h>
#pragma gcc optimize("Ofast")
#define endl '\n'
using namespace std;

using ll = long long;

ll value1(string c)
{
	if (c == "^")
		return 3;
	if (c == "/" || c == "*")
		return 2;
	if (c == "+" || c == "-")
		return 1;
	return 0;
}
vector<string> converse(vector<string> v)
{
	vector<string> res;
	stack<string> st;
	for (ll i = 0; i < v.size(); i++)
	{
		if (isdigit(v[i][0]))
		{
			res.push_back(v[i]);
		}
		else
		{
			if (v[i] == "(")
				st.push(v[i]);
			else
			{
				if (v[i] == ")")
				{
					while (st.size() && (st.top() != "("))
					{
						res.push_back(st.top());
						st.pop();
					}
					st.pop();
				}
				else
				{
					while (st.size() && value1(st.top()) >= value1(v[i]))
					{
						res.push_back(st.top());
						st.pop();
					}
					st.push(v[i]);
				}
			}
		}
	}
	while (st.size())
	{
		res.push_back(st.top());
		st.pop();
	}
	return res;
}
ll calc(ll x, ll y, string c)
{
	if (c == "+")
		return x + y;
	if (c == "-")
		return x - y;
	if (c == "*")
		return x * y;
	if (c == "/")
		return (ll)x / y;
	return 0;
}
ll value(vector<string> v)
{
	stack<ll> st;
	for (ll i = 0; i < v.size(); i++)
	{
		if (isdigit(v[i][0]))
		{
			st.push(stoll(v[i]));
		}
		else
		{
			ll top1 = st.top();
			st.pop();
			ll top2 = st.top();
			st.pop();
			ll res = calc(top2, top1, v[i]);
			st.push(res);
		}
	}
	return st.top();
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
	cin.ignore(1);
	while (t--)
	{
		string s;
		getline(cin, s);
		vector<string> v;
		for (ll i = 0; i < s.size(); i++)
		{

			if (isdigit(s[i]))
			{
				string tam = "";
				while (i < s.size() && isdigit(s[i]))
				{
					tam += s[i];
					i++;
				}
				v.push_back(tam);
				i--;
			}
			else
				v.push_back(string(1, s[i]));
		}
		v = converse(v);
		cout << value(v) << endl;
	}
	return 0;
}