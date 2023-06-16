#include <bits/stdc++.h>
#pragma gcc optimize("Ofast")
#define endl '\n'
using namespace std;

using ll = long long;

int n, s[200], a[200], len;
void add(int x, int delta)
{
	for (int i = 2; i * i <= x; i++)
	{
		while (x % i == 0)
		{
			s[i] += delta;
			x /= i;
		}
	}
	if (x != 1)
		s[x] += delta;
}
void mul(int x)
{
	len += 5;
	for (int i = 0; i < len; i++)
		a[i] *= x;
	for (int i = 0; i < len; i++)
	{
		a[i + 1] += a[i] / 10;
		a[i] %= 10;
	}
	while (len > 0 && !a[len - 1])
		len--;
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
	int t;
	cin >> t;
	while (t--)
	{
		cin >> n;
		memset(a, 0, sizeof(a));
		memset(s, 0, sizeof(s));
		for (int i = 1; i <= n; i++)
			add(2 * n - i + 1, 1);
		for (int i = 1; i <= n + 1; i++)
			add(i, -1);
		a[0] = len = 1;
		for (int i = 1; i < 200; i++)
		{
			while (s[i]--)
				mul(i);
		}
		for (int i = len - 1; i >= 0; i--)
			cout << a[i];
		cout << endl;
	}
	return 0;
}