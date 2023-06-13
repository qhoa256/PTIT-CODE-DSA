#include <bits/stdc++.h>
#pragma gcc optimize("Ofast")
#define endl '\n'
using namespace std;

using ll = long long;

void solve()
{
	string s;
	cin >> s;
	stack<int> st;
	for (int i = 0; i <= s.size(); i++)
	{
		st.push(i + 1);
		if (s[i] == 'I' || i == s.size())
		{
			while (!st.empty())
			{
				cout << st.top();
				st.pop();
			}
		}
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
	int t;
	cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}