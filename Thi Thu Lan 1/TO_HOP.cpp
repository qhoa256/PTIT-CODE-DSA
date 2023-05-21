#include <bits/stdc++.h>
#pragma gcc optimize("Ofast")
#define endl '\n'
using namespace std;

using ll = long long;

int t, k;
string s;
int x[1005];
set<string>se;
void Try(int i) {
	for (int j = x[i - 1] + 1; j <= s.size() - 1 - k + i; j++) {
		x[i] = j;
		if (i == k) {
			string tmp = "";
			for (int h = 1; h <= k; h++) {
				tmp += s[x[h]];
			}
			se.insert(tmp);
		} else Try(i + 1);
	}
}
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> t;
	while (t--) {
		cin >> s >> k;
		s = "@" + s;
		Try(1);
		for (auto &x : se) {
			cout << x << endl;
		}
		se.clear();
	}
	return 0;
}
