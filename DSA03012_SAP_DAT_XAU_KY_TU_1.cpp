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
		string s;
		cin >> s;
		map<char, int>mp;
		int res = 0;
		for (auto x : s) {
			mp[x]++;
			res = max(mp[x], res);
		}
		if (s.size() - res >= res - 1) cout << 1 << endl; else cout << -1 << endl;
	}
	return 0;
}