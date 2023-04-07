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
		int cnt = 0;
		for (char x : s) {
			if (x == '(') {
				st.push(x);
			} else {
				if (st.empty()) {
					st.push('(');
					cnt++;
				} else if (st.top() == '(') {
					st.pop();
				}
			}
		}
		cout << cnt + st.size() / 2 << endl;
	}
	return 0;
}