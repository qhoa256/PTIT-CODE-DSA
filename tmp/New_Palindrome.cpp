#include <bits/stdc++.h>
#pragma gcc optimize("Ofast")
#define endl '\n'
using namespace std;

using ll = long long;

int t;
string s;

bool solve() {
	map<char, int> mp;
	int dem = 1;
	int ok = 1;
	for (int i = 0; i < s.size() / 2; i++) {
		mp[s[i]]++;
		if (mp.size() >= 2) {
			return false;
		}
	}
	return true;
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
		cin >> s;
		if (solve()) cout << "NO\n";
		else cout << "YES\n";
	}
	return 0;
}