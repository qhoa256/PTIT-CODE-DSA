#include <bits/stdc++.h>
#pragma gcc optimize("Ofast")
#define endl '\n'
using namespace std;

using ll = long long;

int bit[1000001];
void update(int i)
{
	for (; i < 1000001; i += i & -i)
		bit[i]++;
}
int get(int i)
{
	int s = 0;
	for (; i; i -= i & -i)
		s += bit[i];
	return s;
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
	int n, ans = 0;
	cin >> n;
	int a[n + 1];
	queue<int> st;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	for (int i = n; i > 0; i--)
	{
		if (a[i] % 2 == 0)
		{
			ans += get(a[i] - 1);
			st.push(a[i]);
		}
		else
		{
			while (!st.empty())
			{
				update(st.front());
				st.pop();
			}
		}
	}
	cout << ans;
	return 0;
}