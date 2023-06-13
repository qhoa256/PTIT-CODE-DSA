#include <bits/stdc++.h>
#pragma gcc optimize("Ofast")
#define endl '\n'
using namespace std;

using ll = long long;

int order(char c) {
	if (c == '+' || c == '-') return 1;
	else if (c == '*' | c == '/') return 2;
	else if (c == '^') return 3;
	else return 0;
}

void hauTo(string s) {
	string res = "";
	stack<char>st;
	for (int i = 0; i < s.size(); i++) {
		if (isalpha(s[i])) res += s[i];
		else if (s[i] == '(') st.push(s[i]);
		else if (s[i] == ')') {
			while (!st.empty() && st.top() != '(') {
				res += st.top();
				st.pop();
			}
			st.pop();
		} else {
			while (!st.empty() && order(st.top()) >= order(s[i])) {
				res += st.top();
				st.pop();
			}
			st.push(s[i]);
		}
	}
	while (!st.empty()) {
		if (st.top() != '(') res += st.top();
		st.pop();
	}
	cout << res << endl;
	//return res;
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
		string s;
		cin >> s;
		hauTo(s);
		//cout << hauTo(s) << endl;
	}
	return 0;
}