#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int n, m;
int a[1005];
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		a[i] = i + 1;
	}
	vector<int>v;
	for (int i = 0; i < n; i++) {
		if (a[i] != m) {
			v.push_back(a[i]);
		}
	}
	do {
		for (auto x : v) {
			cout << x << " ";
		}
		cout << m << endl;
	} while (next_permutation(v.begin(), v.end()));
	return 0;
}