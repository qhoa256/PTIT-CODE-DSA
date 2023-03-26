#include <bits/stdc++.h>

using namespace std;

using ll = long long;

struct job {
	int id, dl, pr;
};
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
		job a[n];
		for (int i = 0; i < n; i++) {
			cin >> a[i].id >> a[i].dl >> a[i].pr;
		}
		sort(a, a + n, [](job a, job b)->bool{
			return a.pr > b.pr;
		});
		int ans = 0, sum = 0, used[100005] = {0};
		for (int i = 0; i < n; i++) {
			for (int j = a[i].dl - 1; j >= 0; j--) {
				if (!used[j]) {
					used[j] = 1;
					sum += a[i].pr;
					ans++;
					break;
				}
			}
		}
		cout << ans << " " << sum << endl;
	}
	return 0;
}