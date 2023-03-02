#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int n, ok = 1, k;
int cnt = 0;
int x[1005];
bool prime(int n) {
	for (int i = 2; i <= sqrt(n); i++) {
		if (n % i == 0) return false;
	}
	return n >= 2;
}

void init() {
	for (int i = 1; i <= k; i++) {
		x[i] = i;
	}
}

void sinh() {
	int i = k;
	while (i >= 1 && x[i] == n - k + i) --i;
	if (i == 0) ok = 0; else {
		x[i]++;
		for (int j = i + 1; j <= k; j++) {
			x[j] = x[j - 1] + 1;
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
	cin >> n >> k;
	init();
	while (ok) {
		cnt++;
		if (prime(cnt)) {
			cout << cnt << ": ";
			for (int i = 1; i <= k; i++) {
				cout << x[i] << " ";
			}
			cout << endl;
		}
		sinh();
	}
	return 0;
}