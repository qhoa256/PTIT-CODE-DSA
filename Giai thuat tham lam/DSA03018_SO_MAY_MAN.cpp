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
		int ok = 0;
		for (int b = n / 7; b >= 0; b--) {
			int remain = n - 7 * b;
			if (remain % 4 == 0) {
				ok = 1;
				for (int i = 0; i < remain / 4; i++) {
					cout << "4";
				}
				for (int i = 0; i < b; i++) {
					cout << "7";
				}
				break;
			}
		}
		if (!ok) cout << -1;
		cout << endl;
	}
	return 0;
}