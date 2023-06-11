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
	int t;
	cin >> t;
	while (t--) {
		string s;
		cin >> s;
		int cnt = 0;
		stack<int>st;
		for (int i = 0; i < s.size(); i++) {
			if (s[i] == '[') {
				st.push(s[i]);
			} else {
				if (st.empty())
				{
					int j = i;
					while (s[j] == ']')
						j++;
					swap(s[i], s[j]);
					cnt += j - i;
					st.push(s[i]);
				}
				else
				{
					st.pop();
				}
			}
		}
		cout << cnt << endl;
	}
	return 0;
}