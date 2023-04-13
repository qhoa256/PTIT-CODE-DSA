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
	cin.ignore();
	while (t--) {
		int cnt = 1;
		int num = 1;
		string s;
		getline(cin, s);
		stack<int>st;
		for (int i = 0; i < s.size(); i++) {
			if (s[i] == '(') {
				st.push(cnt);
				num = cnt;
				cnt++;
			} else if (s[i] == ')') {
				st.push(num);
				num--;
				if (num == 0) {
					num = cnt;
				}
			}
		}
		vector<int>v;
		while (!st.empty()) {
			v.push_back(st.top());
			st.pop();
		}
		for (int i = v.size() - 1; i >= 0; i--) {
			cout << v[i] << " ";
		}
		cout << endl;
	}
	return 0;
}