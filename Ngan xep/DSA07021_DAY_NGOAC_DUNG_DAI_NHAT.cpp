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
		stack<int>st;
		st.push(-1);
		int res = 0;
		for (int i = 0; i < s.size(); i++) {
			if (s[i] == '(') st.push(i);
			else {
				if (!st.empty()) {
					st.pop();
					if (!st.empty()) {
						res = max(res, i - st.top());
					} else {
						st.push(i);
					}
				}
			}
		}
		cout << res << endl;
	}
	return 0;
}