#include <bits/stdc++.h>

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
		string s;
		cin >> k >> s;
		priority_queue<ll>pq;
		map<char, ll>mp;
		for (int i = 0; i < s.size(); i++) {
			mp[s[i]]++;
		}
		for (auto x : mp) {
			pq.push(x.second);
		}
		while (k--) {
			ll x = pq.top();
			pq.pop();
			x--;
			pq.push(x);
		}
		ll res = 0;
		while (!pq.empty()) {
			res += pq.top() * pq.top();
			pq.pop();
		}
		cout << res << endl;
	}
	return 0;
}