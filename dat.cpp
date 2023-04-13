#include <bits/stdc++.h>
#define ll long long
const ll mod = (ll)1e9 + 7;
#define endl "\n"
#define all(v) v.begin(), v.end()
#define ms(a) memset(a, 0, sizeof(a))
#define faster()                  \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);
using namespace std;
ll dx[] = {1, 0, 1};
ll dy[] = {0, 1, 1};
ll n, m, visited[1001][1001], a[1001][1001];
void bfs()
{
	queue<pair<pair<ll, ll>, ll>> qe;
	qe.push({{1, 1}, 0});
	visited[1][1] = 1;
	while (!qe.empty())
	{
		auto it = qe.front();
		qe.pop();
		if (it.first.first == n && it.first.second == m)
		{
			cout << it.second << endl;
			return;
		}
		cout << it.first.first << " " << it.first.second << endl;
		ll x = it.first.first;
		ll y = it.first.second;
		ll cnt1 = 0, cnt2 = 0, cnt3 = 0;
		if (x + 1 <= n)
		{
			cnt1 = abs(a[x + 1][y] - a[x][y]);
		}
		if (y + 1 <= m)
		{
			cnt2 = abs(a[x][y + 1] - a[x][y]);
		}
		if (x + 1 <= n && y + 1 <= m)
		{
			cnt3 = abs(a[x][y] - a[x + 1][y + 1]);
		}
		if (visited[x + cnt1][y] == 0 && (x + cnt1 <= n) && cnt1)
		{
			qe.push({{x + cnt1, y}, it.second + 1});
			visited[x + cnt1][y] = 1;
		}
		if (visited[x][y + cnt2] == 0 && (y + cnt2 <= m) && cnt2)
		{
			qe.push({{x, y + cnt2}, it.second + 1});
			visited[x][y + cnt2] = 1;
		}
		if (visited[x + cnt3][y + cnt3] == 0 && (x + cnt3 <= n) && (y + cnt3 <= m) && cnt3)
		{
			qe.push({{x + cnt3, y + cnt3}, it.second + 1});
			visited[x + cnt3][y + cnt3] = 1;
		}
	}
	cout << -1 << endl;
}
int main()
{
	faster();
	ll t;
	cin >> t;
	while (t--)
	{
		cin >> n >> m;
		for (ll i = 1; i <= n; i++)
		{
			for (ll j = 1; j <= m; j++)
			{
				cin >> a[i][j];
			}
		}
		bfs();
		ms(visited);
	}
}