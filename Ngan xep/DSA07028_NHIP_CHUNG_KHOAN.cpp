#include <bits/stdc++.h>
#pragma gcc optimize("Ofast")
#define endl '\n'
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
		for (int i = 0; i < n; i++) cin >> a[i];
		int d[n];
		stack<int>st;
		for (int i = 0; i < n; i++) {
			while (!st.empty() && a[i] >= a[st.top()]) st.pop();
			if (st.empty()) d[i] = i + 1;
			else d[i] = i - st.top();
			st.push(i);
		}
		for (int i = 0; i < n; i++) {
			cout << d[i] << " ";
		}
		cout << endl;
	}
	return 0;
}