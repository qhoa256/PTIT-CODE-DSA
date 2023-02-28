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
	int n, s;
	cin >> n >> s;
	if (s > 9 * n || s < 1) {
		cout << -1 << " " << -1;
	} else {
		int s1 = s;
		int nho[n] = {0};
		s -= 1;
		for (int i = n - 1; i >= 0; i--) {
			if (s >= 9) {
				nho[i] = 9;
				s -= 9;
			} else {
				nho[i] = s;
				s = 0;
			}
		}
		nho[0] += 1;
		for (int i = 0; i < n; i++) {
			cout << nho[i];
		}
		cout << " ";
		int lon[n] = {0};
		for (int i = 0; i < n; i++) {
			if (s1 >= 9) {
				lon[i] = 9;
				s1 -= 9;
			} else {
				lon[i] = s1;
				s1=0;
			}
		}
		for (int i = 0; i < n; i++) {
			cout << lon[i];
		}
	}
	return 0;
}