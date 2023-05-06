#include <bits/stdc++.h>
#pragma gcc optimize("Ofast")
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
		int n;
		cin >> n;
		int a[n];
		for (auto &x : a) {
			cin >> x;
		}
		stack<int>st;
		int b[n];
		for (int i = 0; i < n; i++) {
			while (!st.empty() && a[st.top()] <= a[i])
				st.pop();
			if (st.empty()) b[i] = i + 1;
			else b[i] = i - st.top();
			st.push(i);
		}
		for (int i = 0; i < n; i++)
			cout << b[i] << " ";
		cout << endl;
	}
	return 0;
}