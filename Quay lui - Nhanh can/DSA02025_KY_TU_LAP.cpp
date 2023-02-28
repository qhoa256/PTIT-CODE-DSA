#include <bits/stdc++.h>
using namespace std;

using ll = long long;
string a[25];
int n, x[1005], cnt[1005][1005], cnt_min = 1e9, min_val = 1e9, used[1005];

int count(string s, string t)
{
	int dem = 0;
	for (int i = 0; i < s.size(); ++i)
	{
		for (int j = 0; j < t.size(); ++j)
		{
			if (s[i] == t[j])
			{
				++dem; break;
			}
		}
	}
	return dem;
}

void init()
{
	for (int i = 1; i <= n; ++i)
	{
		for (int j = i + 1; j <= n; ++j)
		{
			cnt[i][j] = count(a[i], a[j]);
			cnt[j][i] = cnt[i][j];
			cnt_min = min(cnt[i][j], cnt_min);
		}
	}
}

void Try(int i, int sum)
{
	for (int j = 1; j <= n; ++j)
	{
		if (!used[j])
		{
			x[i] = j;
			used[j] = 1;
			if (i == n)
			{
				min_val = min(min_val, sum + cnt[x[i - 1]][j]);
			}
			else if (sum + (n - i + 1) * cnt_min < min_val)
			{
				Try(i + 1, sum + cnt[x[i - 1]][j]);
			}
			used[j] = 0;
		}
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
	for (int i = 1; i <= n; ++i) cin >> a[i];
	init();
	Try(1, 0);
	cout << min_val;
}