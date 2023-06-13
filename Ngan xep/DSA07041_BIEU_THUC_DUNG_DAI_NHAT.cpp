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
		int res = 0;
		for (int i = 0; i < s.size(); i++) {
			if (s[i] == '(') st.push(s[i]);
			else {
				if (!st.empty()) {
					st.pop();
					res += 2;
				}
			}
		}
		cout << res << endl;
	}
	return 0;
}