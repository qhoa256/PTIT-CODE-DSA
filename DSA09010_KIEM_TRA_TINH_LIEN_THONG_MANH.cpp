#include <bits/stdc++.h>

using namespace std;

using ll = long long;

bool visited[1005];
vector<int>adj[1005];
int t, n, m;
int cnt;
void DFS(int s) {
	stack<int>st;
	st.push(s);
	visited[s] = true;
	while (!st.empty()) {
		int x = st.top();
		st.pop();
		for (auto y : adj[x]) {
			if (!visited[y]) {
				cnt++;
				visited[y] = true;
				st.push(x);
				st.push(y);
				break;
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
	cin >> t;
	while (t--) {
		cin >> n >> m;
		for (int i = 0; i < m; i++) {
			int x, y;
			cin >> x >> y;
			adj[x].push_back(y);
		}
		int ok = 1;
		for (int i = 1; i <= n; i++) {
			cnt = 1;
			DFS(i);
			if (cnt < n) {
				ok = 0;
				break;
			}
			memset(visited, false, sizeof(visited));
		}
		if (ok) cout << "YES\n";
		else cout << "NO\n";
		for (int i = 1; i <= n; i++) {
			adj[i].clear();
		}
		memset(visited, false, sizeof(visited));
	}
	return 0;
}