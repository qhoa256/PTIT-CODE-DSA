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
		int n;
		cin >> n;
		int a[n];
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		stack<int>st;
		int res[n];
		for (int i = n - 1; i >= 0; i--) {
			while (!st.empty() && st.top() <= a[i]) st.pop();
			if (st.empty()) res[i] = -1;
			else res[i] = st.top();
			st.push(a[i]);
		}
		for (int i = 0; i < n; i++) {
			cout << res[i] << " ";
		}
		cout << endl;
	}
	return 0;
}