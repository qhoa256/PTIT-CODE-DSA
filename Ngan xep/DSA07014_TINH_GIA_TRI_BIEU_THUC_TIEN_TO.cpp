#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int res(int a, int b, char c) {
	if (c == '+') return a + b;
	else if (c == '-') return a - b;
	else if (c == '*') return a * b;
	else return a / b;
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
		stack<int>st;
		for (int i = s.length() - 1; i >= 0; i--) {
			if (isdigit(s[i])) {
				int t = s[i] - '0';
				st.push(t);
			} else {
				int a = st.top(); st.pop();
				int b = st.top(); st.pop();
				st.push(res(a, b, s[i]));
			}
		}
		cout << st.top() << endl;
	}
	return 0;
}
