#include <bits/stdc++.h>
#pragma gcc optimize("Ofast")
using namespace std;

using ll = long long;

int test, s, t;

int BFS(int s, int t) {
	queue<pair<int, int>>q;
	q.push({s, 0});
	set<int>se;
	se.insert(s);
	while (!q.empty()) {
		auto x = q.front();
		q.pop();
		if (x.first == t) return x.second;
		if (x.first - 1 == t || x.first * 2 == t) return x.second + 1;
		if (x.first > 1 && !se.count(x.first - 1)) {
			q.push({x.first - 1, x.second + 1});
			se.insert(x.first - 1);
		}
		if (x.first < t && !se.count(x.first * 2)) {
			q.push({x.first * 2, x.second + 1});
			se.insert(x.first * 2);
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
	cin >> test;
	while (test--) {
		cin >> s >> t;
		cout << BFS(s, t) << endl;
	}
	return 0;
}