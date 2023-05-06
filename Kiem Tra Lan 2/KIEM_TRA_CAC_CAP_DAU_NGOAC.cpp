#include <bits/stdc++.h>

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
		stack<char>st;
		int ok = 0;
		for (auto x : s) {
			if (x == '(' || x == '[' || x == '{') {
				st.push(x);
			} else {
				if (st.empty()) {
					ok = 1;
					cout << "false" << endl;
					break;
				} else {
					char c = st.top();
					if (c == '(' && x == ')') st.pop();
					else if (c == '[' && x == ']') st.pop();
					else if (c == '{' && x == '}') st.pop();
					else {
						ok = 1;
						cout << "false" << endl;
						break;
					}
				}
			}
		}
		if (!ok) {
			if (st.empty()) cout << "true" << endl;
			else cout << "false" << endl;
		}
	}
	return 0;
}
