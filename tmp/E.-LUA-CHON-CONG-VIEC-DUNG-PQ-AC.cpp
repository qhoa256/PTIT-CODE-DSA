#include<bits/stdc++.h>
using namespace std;

using ll = long long;
struct job {
	int dl, pr;
};

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
		int n;
		cin >> n;
		job a[n];
		for (int i = 0; i < n; i++) {
			cin >> a[i].dl >> a[i].pr;
		}
		sort(a, a + n, [](job a, job b)->bool{
			if (a.dl != b.dl)
				return a.dl > b.dl;
			else return a.pr > b.pr;
		});
		ll dem = 0;
		priority_queue<ll>q;
		ll sum = 0;
		ll tmp = 0;
		for (int i = n; i >= 1; i--) {

			while (tmp < n && a[tmp].dl >= i) {
				q.push(a[tmp].pr);
				tmp++;
			}
			if (!q.empty()) {
				sum += q.top();
				q.pop();
				dem++;
			}

		}
		cout << sum << endl;

}