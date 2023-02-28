#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int t, n, x[1005];
bool vs[1005];

bool check() {
	for (int i = 1; i <= n - 1; i++) {
		if ((x[i] == x[i + 1] - 1) || (x[i] == x[i + 1] + 1)) return false;
	}
	return true;
}
void Try(int i) {
	for (int j = 1; j <= n; j++) {
		if (!vs[j]) {
			vs[j] = 1;
			x[i] = j;
			if (i == n) {
				if (check()) {
					for (int k = 1; k <= n; k++) cout << x[k];
					cout << endl;
				}
			} else Try(i + 1);
			vs[j] = 0;
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
		cin >> n;
		Try(1);
	}
	return 0;
}