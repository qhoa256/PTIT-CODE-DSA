#include <bits/stdc++.h>
#pragma gcc optimize("Ofast")
#define endl '\n'
using namespace std;

using ll = long long;

int t, n, k;

void solve() {
	pair<int, int>  a[n + 1];
	int b[n + 1];
	for (int i = 0; i < n; i++) {
		cin >> a[i].first; a[i].second = i;
	}
	for (int i = 0; i < n; i++) cin >> b[i];
	sort(a, a + n);
	sort(b, b + n);
	for (int i = 0; i < n; i++) {
		a[i].first = b[i];
	}
	sort(a, a + n, [](pair<int, int>a, pair<int, int>b)->bool{
		return a.second < b.second;
	});
	for (int i = 0; i < n; i++) {
		cout << a[i].first << " ";
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
		cin >> n >> k;
		solve();
		cout << endl;
	}
	return 0;
}