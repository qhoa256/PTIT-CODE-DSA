#include <bits/stdc++.h>
#pragma gcc optimize("Ofast")
#define endl '\n'
#define mp make_pair
using namespace std;

using ll = long long;

int n, m, k;
vector<pair<pair<int, int>, pair<int, int>>> vp;
vector<pair<int, int>> a;
int dx[] = { -1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
int f[105][105] = {};
int idx = 0;
int C[100005] = {};

inline bool check(int u, int v, int x, int y)
{
	if (x < 1 or x > n or y < 1 or y > n)
		return 0;
	if (f[x][y])
		return 0;
	for (pair<pair<int, int>, pair<int, int>> &i : vp)
		if ((i.first == mp(u, v) and i.second == mp(x, y)) or (i.first == mp(x, y) and i.second == mp(u, v)))
			return 0;
	return 1;
}

inline void BFS(int x, int y)
{
	f[x][y] = idx;
	queue<pair<int, int>> q;
	pair<int, int> top;
	q.push({x, y});
	while (q.size())
	{
		top = q.front();
		q.pop();
		for (int i = 0; i < 4; ++i)
		{
			if (check(top.first, top.second, top.first + dx[i], top.second + dy[i]))
			{
				f[top.first + dx[i]][top.second + dy[i]] = idx;
				q.push({top.first + dx[i], top.second + dy[i]});
			}
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
	cin >> n >> k >> m;
	int u, v, x, y;
	vp.resize(m);
	a.resize(k);
	for (int i = 0; i < m; ++i)
	{
		cin >> u >> v >> x >> y;
		vp[i].first = {u, v};
		vp[i].second = {x, y};
	}
	for (int i = 0; i < k; ++i)
	{
		cin >> x >> y;
		a[i] = {x, y};
	}
	ll res = 0;
	for (int i = 0; i < a.size(); ++i)
	{
		if (!f[a[i].first][a[i].second])
		{
			++idx;
			BFS(a[i].first, a[i].second);
		}
	}
	ll cnt;
	for (pair<int, int> &i : a)
		++C[f[i.first][i.second]];
	for (int i = 1; i <= idx; ++i)
	{
		cnt = 0;
		for (int j = i + 1; j <= idx; ++j)
			cnt += C[j];
		res += C[i] * cnt;
	}
	cout << res;
	return 0;
}