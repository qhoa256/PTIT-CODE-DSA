#include <bits/stdc++.h>
#pragma gcc optimize("Ofast")
#define endl '\n'
using namespace std;

using ll = long long;

set<string> se;
queue<string> qe;
vector<string> v;
void Delete(string s)
{
	stack<ll> st;
	vector<pair<ll, ll>> res; // luu index cap ngoac
	for (ll i = 0; i < s.size(); i++)
	{
		if (s[i] == '(')
			st.push(i);
		else
		{
			if (s[i] == ')')
			{
				res.push_back({st.top(), i});
				st.pop();
			}
		}
	}
	for (auto &x : res)
	{
		string f = s;
		f = f.erase(x.first, 1);
		f = f.erase(x.second - 1, 1);
		if (!se.count(f))
		{
			se.insert(f);
			qe.push(f);
		}
	}
}
void solve()
{
	string s;
	getline(cin, s);
	Delete(s);
	while (qe.size())
	{
		string top = qe.front();
		qe.pop();
		v.push_back(top);
		Delete(top);
	}
	sort(v.begin(), v.end());
	for (auto &x : v)
		cout << x << endl;
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
	solve();
	return 0;
}