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
		stack<string>st;
		string res = "";
		for (int i = s.length() - 1; i >= 0; i--) {
			if (isdigit(s[i])) {
				st.push(string(1, s[i]));
			} else {
				string x = st.top(); st.pop();
				string y = st.top(); st.pop();
				st.push(x + y + string(1, s[i]));
				res += x + y + string(1, s[i]);
			}
		}
		cout << res << endl;
	}
	return 0;
}