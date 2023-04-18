#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int sz[1005];
int parent[1005];
int t, n;

void init() {
	for (int i = 1; i <= n; i++) {
		parent[i] = i;
		sz[i] = 1;
	}
}
int find(int u) {
	if (u == parent[u])
		return u;
	else
		return parent[u] = find(parent[u]);
}

bool Union(int a, int b) {
	a = find(a);
	b = find(b);
	if (a == b)
		return false;
	if (sz[a] < sz[b]) swap(a, b);
	sz[b] = sz[a];
	sz[a] += sz[b];
	parent[b] = a;
	return true;
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
		init();
		bool ok = true;
		for (int i = 0; i < n - 1; i++) {
			int x, y;
			cin >> x >> y;
			if (!Union(x, y)) ok = false;
		}
		if (!ok) {
			cout << "NO\n";
		} else {
			int cnt = 0;
			for (int i = 1; i <= n; i++) {
				if (parent[i] == i) cnt++;
			}
			if (cnt == 1) cout << "YES\n";
			else cout << "NO\n";
		}
	}
	return 0;
}