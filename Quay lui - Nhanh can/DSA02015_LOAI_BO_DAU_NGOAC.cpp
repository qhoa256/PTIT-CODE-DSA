#include <bits/stdc++.h>
#pragma gcc optimize("Ofast")
#define endl '\n'
using namespace std;

using ll = long long;

vector<string> res;
bool ktra(string s)
{
	int x = 0, y = 0;
	for (int i = 0; i < s.length(); i++)
	{
		if (s[i] == '(')
		{
			x++;
			y++;
		}
		if (s[i] == ')')
			x--;
		if (x < 0)
			return false;
	}
	if (y == 0 && s.length() == 1)
		return false;
	return x == 0;
}
void BFS(string s)
{
	if (!s.length())
		return;
	unordered_set<string> A;
	queue<string> B;
	A.insert(s);
	B.push(s);
	bool ok = false;
	while (B.size())
	{
		string s = B.front();
		B.pop();
		if (ktra(s) && s != "")
		{
			res.push_back(s);
			ok = true;
		}
		if (ok)
			continue;
		for (int i = 0; i < s.length(); i++)
		{
			if (s[i] == '(' || s[i] == ')')
			{
				string a = s.substr(0, i) + s.substr(i + 1, s.length());
				if (A.find(a) == A.end())
				{
					A.insert(a);
					B.push(a);
				}
			}
		}
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
	while (t--)
	{
		res.clear();
		string s;
		cin >> s;
		BFS(s);
		if (res.size() == 0)
			cout << -1;
		else
		{
			sort(res.begin(), res.end());
			for (auto s : res)
				cout << s << " ";
		}
		cout << endl;
	}
	return 0;
}