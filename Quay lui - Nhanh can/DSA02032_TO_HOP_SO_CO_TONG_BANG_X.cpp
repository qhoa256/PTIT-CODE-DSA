#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int t, n, x, a[1005], X[1005], ok;
vector<vector<int>>v;
void Try(int i, int sum) {
	for (int j = 1; j <= n; j++) {
		if (a[j] >= X[i - 1] && sum + a[j] <= x) {
			X[i] = a[j];
			if (sum + a[j] == x) {
				ok = 1;
				vector<int>tmp(X + 1, X + i + 1);
				v.push_back(tmp);
			} else Try(i + 1, sum + a[j]);
		}
	}
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
	cin >> t;
	while (t--) {
		ok = 0;
		cin >> n >> x;
		for (int i = 1; i <= n; i++) {
			cin >> a[i];
		}
		Try(1, 0);
		if (!ok) cout << -1; else {
			cout << v.size() << " ";
			for (int i = 0; i < v.size(); i++) {
				cout << "{";
				for (int j = 0; j < v[i].size(); j++) {
					cout << v[i][j];
					if (j != v[i].size() - 1) cout << " ";
				}
				cout << "} ";
			}
		}
		cout << endl;
		v.clear();
	}
	return 0;
}