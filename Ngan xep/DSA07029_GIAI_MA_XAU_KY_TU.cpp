#include <bits/stdc++.h>
#pragma gcc optimize("Ofast")
#define endl '\n'
using namespace std;

using ll = long long;

void solve(string s) {
	stack<char>st;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] != ']') st.push(s[i]);
		else {
			string res = "";
			while (!st.empty() && st.top() != '[') {
				res = st.top() + res;
				st.pop();
			}
			st.pop();
			string num = "";
			while (!st.empty() && isdigit(st.top())) {
				num = st.top() + num;
				st.pop();
			}
			int cnt = 1;
			if (num != "") cnt = stoll(num);
			string ss = "";
			while (cnt--) {
				ss += res;
			}
			for (auto &x : ss) st.push(x);
		}
	}
	string qhoa = "";
	while (!st.empty())
	{
		qhoa += st.top();
		st.pop();
	}
	reverse(qhoa.begin(), qhoa.end());
	cout << qhoa << endl;
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
	cin.ignore();
	while (t--) {
		string s;
		cin >> s;
		solve(s);
	}
	return 0;
}