#include <bits/stdc++.h>
#define ll long long
const ll mod = (ll)1e9 + 7;
#define endl "\n"
#define all(v) v.begin(), v.end()
#define ms(a) memset(a, 0, sizeof(a))
#define faster()                  \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);
using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	faster();
	ll t;
	cin >> t;
	cin.ignore();
	while (t--)
	{
		string s;
		cin >> s;
		stack<char> st;
		ll cnt1 = 0, cnt2 = 0;
		for (ll i = 0; i < s.size(); i++)
		{
			if (!st.empty())
			{
				if (s[i] == ')' && st.top() == '(')
				{
					st.pop();
				}
				else
				{
					if (s[i] == ']' && st.top() == '[')
					{
						st.pop();
						cnt2++;
					}
					else
					{
						st.push(s[i]);
					}
				}
			}
			else
				st.push(s[i]);
		}
		cout << cnt2 << endl;
	}
}