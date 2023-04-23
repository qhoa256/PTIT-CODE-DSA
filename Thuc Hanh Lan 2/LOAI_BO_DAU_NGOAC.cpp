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
		string s2;
		getline(cin, s2);
		stack<char>st;
		string res = "";
		string s = "";
		for (char x : s2) {
			if (x != ' ') {
				s += x;
			}
		}
		for (int i = 0; i < s.length(); i++) {
			char c = s[i];
			if (isalpha(c) || c == '+' || c == '-') {
				st.push(c);
			} else if (!st.empty() && st.top() == '-' && c == '(') {
				st.push(c);
			} else if (c == ')') {
				while (!st.empty() && st.top() != '(') {
					res = string(1, st.top()) + res;
					st.pop();
				}
				if (!st.empty()) {
					res += st.top();
					st.pop();
				}
				res += ')';
			}
		}
		while (!st.empty()) {
			res = string(1, st.top()) + res;
			st.pop();
		}
		cout << res << endl;
	}
	return 0;
}