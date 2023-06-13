#include <bits/stdc++.h>
#pragma gcc optimize("Ofast")
#define endl '\n'
using namespace std;

using ll = long long;

ll merge(int a[], int l, int r, int m)
{
	vector<int> x(a + l, a + m + 1);
	vector<int> y(a + m + 1, a + r + 1);
	ll cnt = 0;
	int i = 0, j = 0;
	while (i < x.size() && j < y.size())
	{
		if (x[i] > y[j])
		{
			cnt += x.size() - i;
			a[l++] = y[j++];
		}
		else
		{
			a[l++] = x[i++];
		}
	}
	while (i < x.size())
		a[l++] = x[i++];
	while (j < y.size())
		a[l++] = y[j++];
	return cnt;
}

ll mergeSort(int a[], int l, int r)
{
	ll ans = 0;
	if (l < r)
	{
		int m = (l + r) / 2;
		ans += mergeSort(a, l, m);
		ans += mergeSort(a, m + 1, r);
		ans += merge(a, l, r, m);
	}
	return ans;
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
	ll t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		int a[n];
		for (int i = 0; i < n; i++)
			cin >> a[i];
		cout << mergeSort(a, 0, n - 1) << endl;
	}
	return 0;
}