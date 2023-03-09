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
		map<int, int>mp, mp1, mp2, mp3;
		int n, m, k;
		cin >> n >> m >> k;
		int a[n], b[m], c[k];
		for (auto &x : a) {
			cin >> x;
			mp[x] = 1;
			mp1[x]++;
		}
		for (auto &x : b) {
			cin >> x;
			if (mp[x] == 1) mp[x] = 2;
			mp2[x]++;
		}
		for (auto &x : c) {
			cin >> x;
			if (mp[x] == 2) mp[x] = 3;
			mp3[x]++;
		}
		int ok = 0;
		for (auto x : mp) {
			if (x.second == 3) {
				ok = 1;
				for (int i = 0; i < min({mp1[x.first], mp2[x.first], mp3[x.first]}); i++) {
					cout << x.first << " ";
				}
			}
		}
		if (!ok) cout << "NO";
		cout << endl;
	}
	return 0;
}