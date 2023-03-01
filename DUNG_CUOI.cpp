#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int n;
string s[1005];
string tmp;

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
		cin >> s[i];
	}
	cin >> tmp;
	vector<string>v;
	for (int i = 1; i <= n; i++) {
		if (s[i] != tmp) v.push_back(s[i]);
	}
	sort(v.begin(), v.end());
	do {
		for (int i = 0; i < v.size(); i++) {
			cout << v[i] << " ";
		}
		cout << tmp << endl;
	} while (next_permutation(v.begin(), v.end()));
	return 0;
}