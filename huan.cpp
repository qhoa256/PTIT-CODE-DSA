#include <bits/stdc++.h>
using namespace std;

using ll = long long;

bool solve(string s)
{
	stack<char> st;

	for (char c : s)
	{
		if (c == ')')
		{
			int ok = 1;
			while (!st.empty() && st.top() != '(')
			{
				char x = st.top(); st.pop();
				if (x == '+' || x == '-' || x == '*' || x == '/') ok = 0;
			}
			st.pop();
			if (ok) return false;
		}
		else st.push(c);
	}
	return true;
}

int main(int argc, char **argv)
{
	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif
	int t; cin >> t;
	while (t--)
	{
		string s; cin >> s;
		if (solve(s)) cout << "Yes\n";
		else cout << "No\n";
	}
}