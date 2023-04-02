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
	string s;
	cin >> s;
	int F[1005];
	int ans = INT_MIN;
	for (int i = 0; i < s.size(); i++) {
		F[i] = 1;
		for (int j = 0; j < i; j++) {
			if (s[j] <= s[i])
				F[i] = max(F[i], F[j] + 1);
		}
		ans = max(ans, F[i]);
	}
	cout << ans;
	return 0;
}