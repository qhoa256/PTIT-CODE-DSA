#include <bits/stdc++.h>
using namespace std;
int n, m;
int check(string x) {
	int d[6] = {0};
	for (int i = 0; i < x.size(); i++) {
		d[x[i] - '0']++;
		if (d[x[i] - '0'] >= 2) return 0;
	}
	if (stoi(x) >= n && stoi(x) <= m) return 1;
}
int ans() {
	int dem = 0;
	for (int i = 0; i <= 5; i++) {
		queue<string>q;
		q.push(string(1, i + '0'));
		while (1) {
			string x = q.front(); q.pop();
			if (stoi(x) > m) break;
			if (check(x)) {
				dem++;
				cout << stoi(x) << endl;
			}
			q.push(x + '0');
			q.push(x + '1');
			q.push(x + '2');
			q.push(x + '3');
			q.push(x + '4');
			q.push(x + '5');
		}
	}
	return dem;
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int t; cin >> t;
	while (t--) {
		cin >> n >> m;
		cout << ans() << endl;
	}
}