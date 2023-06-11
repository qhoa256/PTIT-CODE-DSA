#include <bits/stdc++.h>
#pragma gcc optimize("Ofast")
#define endl '\n'
using namespace std;

using ll = long long;

ll cnt[26] = {0};

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t; cin >> t;
	while (t--)
	{
		int d;
		string s;
		cin >> d >> s;
		for (auto x : s)
		{
			cnt[x - 'A']++;
		}
		int res = *max_element(cnt, cnt + 26);
		int k = s.size() - (d - 1) * (res - 1);
		if (res <= k) cout << "1\n";
		else cout << "-1\n";
		memset(cnt, 0, sizeof(cnt));
	}
	return 0;
}
