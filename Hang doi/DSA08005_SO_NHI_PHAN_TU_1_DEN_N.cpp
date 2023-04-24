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
	ll t;
	cin >> t;
	while (t--) {
		ll n;
		cin >> n;
		queue<string>q;
		q.push("1");
		int cnt = 0;
		while (1) {
			string x = q.front();
			q.pop();
			if (cnt == n) break;
			cout << stoll(x) << " ";
			cnt++;
			q.push(x + "0");
			q.push(x + "1");
		}
		cout << endl;
	}
	return 0;
}