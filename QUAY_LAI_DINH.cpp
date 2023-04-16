#include <bits/stdc++.h>

using namespace std;

using ll = long long;

vector<int>adj[1005];
int degree[1005];
int mark[1005];
int n, m;
void kahn() {
	queue<int>q;
	queue<int>res;
	for (int i = 1; i <= n; i++) {
		if (degree[i] == 0) q.push(i);
	}
	int cnt = 0;
	while (!q.empty()) {
		int v = q.front(); q.pop();
		cnt++;
		mark[v] = 1;
		for (auto &x : adj[v]) {
			degree[x]--;
			if (degree[x] == 0) {
				q.push(x);
				res.push(x);
			}
		}
	}
	while (!res.empty()) {
		cout << res.front() << endl;
		res.pop();
	}
	//return cnt == n;
	// int res = 0;
	// for (int i = 1; i <= n; i++) {
	// 	if (!mark[i]) res++;
	// }
	// return n - res.size();
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
	while (t--) {
		cin >> n >> m;
		for (int i = 0; i < m; i++) {
			int x, y;
			cin >> x >> y;
			adj[x].push_back(y);
			degree[y]++;
		}
		for (int i = 1; i <= n; i++) {
			cout << degree[i] << " ";
		}
		//cout << kahn() << endl;
		kahn();
		memset(degree, 0, sizeof(degree));
		memset(mark, 0, sizeof(mark));
		memset(adj, 0, sizeof(adj));
	}
	return 0;
}