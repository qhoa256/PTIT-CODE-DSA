#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int t, n, a[1005];

vector<vector<int>>v;

void Try(int i, vector<int>tmp, int sum) {
	for (int j = i + 1; j <= n; j++) {
		tmp.push_back(a[j]);
		if ((sum + a[j]) % 2)
			v.push_back(tmp);
		Try(j, tmp, sum + a[j]);
		tmp.pop_back();
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
		cin >> n;
		for (int i = 1; i <= n; i++) {
			cin >> a[i];
		}
		sort(a + 1, a + n + 1, greater<int>());
		vector<int>tmp;
		Try(0, tmp, 0);
		sort(v.begin(), v.end());
		for (auto x : v) {
			for (auto y : x) {
				cout << y << " ";
			}
			cout << endl;
		}
		v.clear();
	}
	return 0;
}