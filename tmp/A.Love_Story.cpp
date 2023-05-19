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
	string res = "";
	res += "codeforces";
	int t;
	cin >> t;
	while (t--) {
		string s;
		cin >> s;
		for (int i = 0; i < s.size(); i++) {
			if (s[i] != res[i]) cnt++;
		}
		cout << cnt << endl;
	}
	return 0;
}