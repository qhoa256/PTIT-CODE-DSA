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
		queue<int>q;
		int tv;
		cin >> tv;
		while (tv--) {
			int x;
			cin >> x;
			if (x == 1) {
				cout << q.size() << endl;
			} else if (x == 2) {
				if (!q.empty()) cout << "NO\n"; else cout << "YES\n";
			} else if (x == 3) {
				int y;
				cin >> y;
				q.push(y);
			} else if (x == 4) {
				if (!q.empty()) q.pop();
			} else if (x == 5) {
				if (!q.empty()) {
					cout << q.front() << endl;
				} else {
					cout << -1 << endl;
				}
			} else {
				if (!q.empty()) cout << q.back() << endl; else cout << -1 << endl;
			}
		}
	}
	return 0;
}