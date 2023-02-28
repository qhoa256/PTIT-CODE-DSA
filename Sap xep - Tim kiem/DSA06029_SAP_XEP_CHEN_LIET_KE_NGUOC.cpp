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
	int n;
	cin >> n;
	int a[n];
	for (auto &x : a) cin >> x;
	vector<vector<int>>v;
	vector<int>tmp(a, a + 1);
	v.push_back(tmp);
	for (int i = 1; i < n; i++) {
		int pos = i - 1, val = a[i];
		while (pos >= 0 && val < a[pos]) {
			a[pos + 1] = a[pos];
			--pos;
		}
		a[pos + 1] = val;
		vector<int>tmp1(a, a + i + 1);
		v.push_back(tmp1);
	}
	for (int i = v.size() - 1; i >= 0; i--) {
		cout << "Buoc " << i << ": ";
		for (auto x : v[i]) cout << x << " ";
		cout << endl;
	}
	return 0;
}