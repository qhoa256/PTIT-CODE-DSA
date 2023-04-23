#include <bits/stdc++.h>

using namespace std;

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int a, b;
	cin >> a >> b;
	queue<long long> q;
	q.push(4);
	q.push(7);
	long long kq = 0;
	int dem = a;
	while (1) {
		long long tmp = q.front();
		q.pop();
		while (dem <= tmp && dem <= b) {
			kq += tmp;
			dem++;
		}
		if (dem > b) break;
		q.push(tmp * 10 + 4);
		q.push(tmp * 10 + 7);
	}
	cout << kq;
}