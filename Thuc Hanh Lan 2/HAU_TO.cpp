#include <bits/stdc++.h>

using namespace std;

using ll = long long;

ll calc(ll x, ll y, string c) {
	if (c == "+") return x + y;
	else if (c == "-") return x - y;
	else if (c == "*") return x * y;
	else return x / y;
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
		int n;
		cin >> n;
		vector<string>v;
		for (int i = 0; i < n; i++) {
			string s;
			cin >> s;
			v.push_back(s);
		}
		stack<ll>st;
		for (int i = 0; i < v.size(); i++) {
			if (v[i] == "+" || v[i] == "-" || v[i] == "*" || v[i] == "/") {
				ll x = st.top(); st.pop();
				ll y = st.top(); st.pop();
				st.push(calc(y, x, v[i]));
			} else {
				st.push(stoll(v[i]));
			}
		}
		cout << st.top() << endl;
	}
	return 0;
}