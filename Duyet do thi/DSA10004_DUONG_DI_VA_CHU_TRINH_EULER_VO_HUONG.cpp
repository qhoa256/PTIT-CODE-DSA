#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int t, n, m;
int deg[1005];
vector<int>adj[1005];
int zero[1005];
int visited[1005];

void DFS(int u) {
	visited[u] = true;
	for (auto &x : adj[u]) {
		if (!visited[x]) DFS(x);
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
		bool dk1 = false, dk2 = true, dk3 = false;
		//DK1: TAT CA CAC DINH DEU CO BAC CHAN
		//DK2: CAC DINH CO BAC KHAC 0 CUA DO THI LIEN THONG VOI NHAU
		//DK3: DO THI CO 0 HOAC 2 DINH BAC LE
		cin >> n >> m;
		for (int i = 0; i < m; i++) {
			int x, y;
			cin >> x >> y;
			adj[x].push_back(y);
			adj[y].push_back(x);
			deg[x]++;
			deg[y]++;
		}
		int chan = 0, le = 0;
		for (int i = 1; i <= n; i++) {
			if (deg[i] % 2 == 0) chan++;
			else le++;
			if (deg[i] == 0) zero[i] = true;
		}
		if (chan == n) dk1 = true;
		for (int i = 1; i <= n; i++) {
			if (!zero[i]) {
				DFS(i);
				break;
			}
		}
		for (int i = 1; i <= n; i++) {
			if (zero[i] == false && visited[i] == false) {
				dk2 = false;
				break;
			}
		}
		if (le == 0 || le == 2) dk3 = true;
		if (dk2 && dk1) cout << 2 << endl;
		else if (dk2 && dk3) cout << 1 << endl;
		else cout << 0 << endl;
		memset(visited, 0, sizeof(visited));
		memset(deg, 0, sizeof(deg));
		memset(zero, 0, sizeof(zero));
		for (int i = 1; i <= n; i++) {
			adj[i].clear();
		}
	}
	return 0;
}