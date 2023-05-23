#include <bits/stdc++.h>
#pragma gcc optimize("Ofast")
#define endl '\n'
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
	ll n, k;
	cin >> n >> k;
	priority_queue<ll, vector<ll>, greater<ll>>pq;
	for (int i = 0; i < n; i++) {
		ll x;
		cin >> x;
		pq.push(x);
	}
	ll tmp = k;
	ll tien = 0;
	while (pq.size() > 1) {
		ll sum = 0, lon = 0, nho = 0;
		if (pq.size() >= k) {
			while (tmp--) {
				if (tmp == k - 1) nho = pq.top();
				if (tmp == 0) lon = pq.top();
				sum += pq.top();
				pq.pop();
			}
		} else {
			ll hoa = pq.size();
			while (!pq.empty()) {
				if (pq.size() == hoa) nho = pq.top();
				if (pq.size() == 1) lon = pq.top();
				sum += pq.top();
				pq.pop();
			}
		}
		tmp = k;
		tien += lon - nho;
		pq.push(sum);
	}
	cout << pq.top() << "\n" << tien;
	return 0;
}