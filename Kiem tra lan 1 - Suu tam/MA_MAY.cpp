#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int n;
string s = "";
int x[1005];
vector<vector<int>>v;
void Try(int i) {
	for (int j = 1; j <= n; j++) {
		x[i] = j;
		if (i == n) {
			vector<int>tmp(x + 1, x + n + 1);
			v.push_back(tmp);
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
	cin >> n;
	for (int i = 1; i <= n; i++) {
		s += ('A' + i - 1);
	}
	Try(1);
	do {
		for (auto x : v) {
			cout << s;
			for (auto y : x) {
				cout << y;
			}
			cout << endl;
		}
	} while (next_permutation(s.begin(), s.end()));
	return 0;
}