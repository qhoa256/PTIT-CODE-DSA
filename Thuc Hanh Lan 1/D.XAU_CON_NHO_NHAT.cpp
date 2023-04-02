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
		set<char>se;
		for (int i = 0; i < s.size(); i++) {
			se.insert(s[i]);
		}
		int k = se.size();
		map<char, int>mp;
		int l = 0, MIN = INT_MAX;
		for (int r = 0; r < s.size(); r++) {
			mp[s[r]]++;
			while (mp.size() == k) {
				MIN = min(MIN, r - l + 1);
				mp[s[l]]--;
				if (mp[s[l]] == 0) mp.erase(s[l]);
				++l;
			}
		}
		cout << MIN << endl;
	}
	return 0;
}