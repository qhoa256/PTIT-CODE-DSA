#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int n, x[1005], a[1005];
void init() {
	a[1] = 2;
	a[2] = 3;
	a[3] = 5;
	a[4] = 7;
}

bool check() {
	int cnt[1005]={0};
	for (int i = 1; i <= n; i++) {
		cnt[x[i]]++;
	}
	return cnt[2] != 0 && cnt[3] != 0 && cnt[5] != 0 && cnt[7] != 0 && x[n] != 2;
}
void Try(int i) {
	for (int j = 1; j <= 4; j++) {
		x[i] = a[j];
		if (i == n) {
			if (check()) {
				for (int k = 1; k <= n; k++) {
					cout << x[k];
				}
				cout << endl;
			}
		} else Try(i + 1);
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
	init();
	cin >> n;
	Try(1);
	return 0;
}