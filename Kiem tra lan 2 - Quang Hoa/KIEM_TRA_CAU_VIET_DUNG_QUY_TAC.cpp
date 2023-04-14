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
	cin.ignore();
	while (t--) {
		string s;
		getline(cin, s);
		vector<char>v;
		for (int i = 0; i < s.size(); i++) {
			if (s[i] == ']' || s[i] == ')' || s[i] == '(' || s[i] == '[') {
				v.push_back(s[i]);
			} else {
				continue;
			}
		}
		stack<char>st;
		int ok = 0;
		for (auto x : v) {
			if (x == '(' || x == '[') {
				st.push(x);
			} else if (x == ')' || x == ']') {
				if (st.empty()) {
					ok = 1;
					cout << "NO" << endl;
					break;
				} else {
					char c = st.top();
					if (c == '(' && x == ')') st.pop();
					else if (c == '[' && x == ']') st.pop();
					else {
						ok = 1;
						cout << "NO" << endl;
						break;
					}
				}
			}
		}
		if (!ok) {
			if (st.empty()) cout << "YES" << endl;
			else cout << "NO" << endl;
		}

	}
	return 0;
}