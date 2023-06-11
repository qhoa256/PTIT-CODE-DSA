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
		for (int i = 0; i < s.size(); i++) {
			if (s[i] != '(' && s[i] != ')') cout << s[i];
		}
		cout << endl;
	}
	return 0;
}