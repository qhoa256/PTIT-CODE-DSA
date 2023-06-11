#include <bits/stdc++.h>
#pragma gcc optimize("Ofast")
#define endl '\n'
using namespace std;

using ll = long long;

string solve(string s) {
	stack<char>st;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == '(') {
			st.push(i);
		} else if (s[i] == ')') {
			if (!st.empty()) {
				int idx = st.top(); st.pop();
				if (idx == 0) continue;
				if (s[idx - 1] == '+') continue;
				if (s[idx - 1] == '-') {
					for (int j = idx + 1; j <= i - 1; j++) {
						if (s[j] == '+') s[j] = '-';
						else if (s[j] == '-') s[j] = '+';
					}
				}
			}
		}
	}
	string res = "";
	for (int i = 0; i < s.size(); i++) {
		if (s[i] != '(' && s[i] != ')') res += s[i];
	}
	return res;
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
		string s1, s2;
		cin >> s1 >> s2;
		s1 = solve(s1);
		s2 = solve(s2);
		if (s1 == s2) cout << "YES\n";
		else cout << "NO\n";
	}
	return 0;
}