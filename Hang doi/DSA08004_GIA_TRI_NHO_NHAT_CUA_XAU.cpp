#include <bits/stdc++.h>
#pragma gcc optimize("Ofast")
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
	int t;
	cin >> t;
	while (t--) {
		int k;
		cin >> k;
		string s;
		cin >> s;
		map<char, int>mp;
		for (auto &x : s) {
			mp[x]++;
		}
		priority_queue<pair<int, char>>pq;
		for (auto &x : mp) {
			pq.push({x.second, x.first});
		}
		while (k--) {
			auto x = pq.top();
			char a = x.second;
			int b = x.first;
			pq.pop();
			pq.push({b - 1, a});
		}
		ll res = 0;
		while (!pq.empty()) {
			auto x = pq.top();
			pq.pop();
			res += (ll)pow(x.first, 2);
		}
		cout << res << endl;
	}
	return 0;
}