#include <bits/stdc++.h>
#pragma gcc optimize("Ofast")
using namespace std;

using ll = long long;

int t, n;

int BFS(int n) {
	map<int, int>mp;
	queue<pair<int, int>>q;
	q.push({n, 0});
	while (!q.empty()) {
		auto x = q.front();
		q.pop();
		if (x.first == 1) return x.second;
		if (x.first - 1 == 1) return x.second + 1;
		if (x.first > 2 && !mp[x.first - 1]) {
			q.push({x.first - 1, x.second + 1});
			mp[x.first - 1]++;
		}
		for (int i = 2; i <= sqrt(x.first); i++)
		{
			if (x.first % i == 0 && !mp[x.first / i])
			{
				mp[x.first / i]++;
				q.push({x.first / i, x.second + 1});
			}
		}
	}
	return 0;
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
	cin >> t;
	while (t--) {
		cin >> n;
		cout << BFS(n) << endl;
	}
	return 0;
}