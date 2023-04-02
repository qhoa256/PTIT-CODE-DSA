#include <bits/stdc++.h>

using namespace std;

using ll = long long;
const int p = 1e6;

int prime[p + 1];

void sieve() {
	for (int i = 0; i <= p; i++) {
		prime[i] = 1;
	}
	prime[0] = prime[1] = 0;
	for (int i = 0; i <= sqrt(p); i++) {
		if (prime[i]) {
			for (int j = i * i; j <= p; j += i) {
				prime[j] = 0;
			}
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
	sieve();
	int t;
	cin >> t;
	while (t--) {
		int l, r;
		cin >> l >> r;
		ll sum = 0;
		for (int i = l; i <= r; i++) {
			int MAX = 0;
			int tmp = i;
			for (int k = 1; k <= sqrt(tmp); k++) {
				if (tmp % k == 0) {
					if (prime[k]) {
						MAX = max(MAX, k);
					}
					if (prime[tmp / k]) {
						MAX = max(MAX, tmp / k);
					}
				}
			}
			sum += 1ll * MAX;
		}
		cout << sum << endl;
	}
	return 0;
}