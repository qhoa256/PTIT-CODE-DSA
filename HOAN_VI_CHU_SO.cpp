#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int t;
string s;

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
		sort(s.begin(), s.end());
		do {
			ll tmp=stoll(s);
			cout << tmp << endl;
		} while (next_permutation(s.begin(), s.end()));
	}
	return 0;
}