#include <bits/stdc++.h>

using namespace std;

using ll = long long;

vector<int>adj[1005];
bool visited[1005];
vector<pair<int, int>>p;
int t, n, m;
void DFS(int s) {
	stack<int>st;
	st.push(s);
	visited[s] = true;
	while (st.size()) {
		int x = st.top();
		st.pop();
		for (auto y : adj[x]) {
			if (!visited[y]) {
				visited[y] = true;
				st.push(x);
				st.push(y);
				break;
			}
		}
	}
}

void DFS2(int s, int u, int v) {
	visited[s] = true;
	for (auto x : adj[s]) {
		if (!visited[x]) {
			if ((x == u && s == v) || (x == v && s == u)) continue;
			DFS2(x, u, v);
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
	cin >> t;
	while (t--) {
		memset(visited, false, sizeof(visited));
		cin >> n >> m;
		for (int i = 1; i <= m; i++) {
			int x, y;
			cin >> x >> y;
			adj[x].push_back(y);
			adj[y].push_back(x);
			p.push_back({min(x, y), max(x, y)});
		}
		sort(p.begin(), p.end());
		int tplt = 0;
		for (int i = 1; i <= n; i++) {
			if (!visited[i]) {
				DFS(i);
				tplt++;
			}
		}
		memset(visited, false, sizeof(visited));
		for (auto x : p) {
			int cnt = 0;
			for (int i = 1; i <= n; i++) {
				if (!visited[i]) {
					cnt++;
					DFS2(i, x.first, x.second);
				}
			}
			if (cnt > tplt) {
				cout << x.first << " " << x.second << " ";
			}
			memset(visited, false, sizeof(visited));
		}
		cout << endl;
		for (int i = 1; i <= n; i++) {
			adj[i].clear();
		}
		p.clear();
	}
	return 0;
}