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
	string s;
	while (cin >> s) {
		if (s == "push") {
			ll n;
			cin >> n;
			cin.ignore();
			st.push(n);
		} else if (s == "pop") {
			st.pop();
		} else {
			vector<ll>v;
			if (st.empty()) {
				cout << "empty\n";
			} else {
				while (!st.empty()) {
					ll tmp = st.top();
					st.pop();
					v.push_back(tmp);
				}
				for (int i=v.size()-1;i>=0;i--) {
					cout << v[i] << " ";
					st.push(v[i]);
				}
				cout << endl;
			}
		}
	}
	return 0;
}