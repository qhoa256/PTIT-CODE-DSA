#include<bits/stdc++.h>
using namespace std;
int a[200005], b[200005];
int main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		priority_queue<int> q;
		for (int i = 0; i < n; i++) cin >> a[i];
		for (int i = 0; i < n; i++) {
			int x; cin >> x;
			q.push(x);
		}
		sort(a, a + n);
		long long dem = 1;
		int ok = 1;
		for (int i = n - 1; i >= 0; i--) {
			int k = q.top(); q.pop();
			int x = a + i + 1 - upper_bound(a, a + i + 1, k);
			if (x == 0) {
				ok = 0; break;
			}
			else {
				dem *= x ; dem %= (long long) (1e9 + 7);
			}
		}
		if (!ok) cout << "0" << endl;
		else cout << dem << endl;

	}
}