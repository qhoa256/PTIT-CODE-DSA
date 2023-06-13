#include <bits/stdc++.h>
#pragma gcc optimize("Ofast")
#define endl '\n'
using namespace std;

using ll = long long;

struct value
{
	ll x, y, w;
};
ll dx[] = { -2, -2, -1, -1, 1, 1, 2, 2};
ll dy[] = { -1, 1, -2, 2, -2, 2, -1, 1};
ll bfs(ll x, ll y, ll z, ll t)
{
	queue<value> qe;
	qe.push({x, y, 0});
	ll a[9][9];
	memset(a, 0, sizeof(a));
	a[x][y] = 1;
	while (!qe.empty())
	{
		value v = qe.front();
		qe.pop();
		if (v.x == z && v.y == t)
			return v.w;
		for (int i = 0; i < 8; i++)
		{
			ll nx = v.x + dx[i];
			ll ny = v.y + dy[i];
			if (nx >= 1 && nx < 9 && ny >= 1 && ny < 9 && a[nx][ny] == 0)
			{
				a[nx][ny] = 1;
				qe.push({nx, ny, v.w + 1});
			}
		}
	}
	return -1;
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
		char x, y;
		ll x1, y1;
		cin >> x >> x1 >> y >> y1;
		ll z = x - (ll)('a' - 1);
		ll k = y - (ll)('a' - 1);
		cout << bfs(z, x1, k, y1) << endl;
	}
	return 0;
}