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
	stack<ll>st;
	int t;
	cin >> t;
	string s;
	cin.ignore();
	while (t--) {
		cin >> s;
		if (s == "PUSH") {
			ll x;
			cin >> x;
			cin.ignore();
			st.push(x);
		} else if (s == "POP") {
			if (!st.empty()) {
				st.pop();
			}
		} else {
			if (!st.empty()) {
				cout << st.top() << endl;
			} else {
				cout << "NONE\n";
			}
		}
	}
	return 0;
}