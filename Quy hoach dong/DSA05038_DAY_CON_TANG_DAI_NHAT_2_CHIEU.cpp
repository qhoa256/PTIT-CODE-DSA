#include <bits/stdc++.h>
#pragma gcc optimize("Ofast")
#define endl '\n'
using namespace std;

using ll = long long;

int n;
map<int, int> dp[100000];
map<int, int>::iterator ite1, ite2;

void Add(int th, int x, int y)
{
	ite1 = dp[th].lower_bound(x);
	ite2 = ite1;
	while (ite2 != dp[th].end() && ite2->second >= y)
		ite2++;
	dp[th].erase(ite1, ite2);
	dp[th].insert({x, y});
}

bool check(int th, int x, int y)
{
	ite1 = dp[th].lower_bound(x);
	if (ite1 == dp[th].begin())
		return false;
	ite1--;
	return ite1->second < y;
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
	Add(0, INT_MIN, INT_MIN);
	int res = 0;
	for (int i = 0; i < n; i++)
	{
		int x, y;
		cin >> x >> y;
		int l = 0, r = res;
		while (l <= r)
		{
			int mid = (l + r) / 2;
			if (check(mid, x, y))
				l = mid + 1;
			else
				r = mid - 1;
		}
		if (res == l - 1)
			res = l;
		Add(l, x, y);
	}
	cout << res << endl;
	return 0;
}