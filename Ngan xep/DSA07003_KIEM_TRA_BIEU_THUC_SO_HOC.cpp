#include <bits/stdc++.h>

using namespace std;

using ll = long long;

bool check(string s) {
	int n = s.size();
	stack<int>st;
	st.push(-1);
	for (int i = 0; i < n; i++) {
		if (s[i] == '(') st.push(i);
		else if (s[i] == ')') {
			int j = st.top();
			st.pop();
			if ((i - j == 2) || ((s[j + 1] == '(') && (s[i - 1] == ')')))
				return true;

		}
	}
	return false;
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
		if (check(s)) cout << "Yes\n";
		else cout << "No\n";
	}
	return 0;
}