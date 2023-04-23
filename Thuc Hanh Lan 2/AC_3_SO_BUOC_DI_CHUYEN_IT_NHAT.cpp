#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int dx[3] = {1, 0, 1};
int dy[3] = {0, 1, 1};

int n, m;

int visited[1005][1005], A[1005][1005];

int BFS() {
	queue<pair<pair<int, int>, int>>q;
	q.push({{1, 1}, 0});
	visited[1][1] = 1;
	while (!q.empty()) {
		auto x = q.front();
		q.pop();
		if (x.first.first == n && x.first.second == m) {
			return x.second;
		}
		int a = x.first.first, b = x.first.second;
		int step1 = 0, step2 = 0, step3 = 0;
		for (int k = 0; k < 3; k++) {
			int a1 = x.first.first + dx[k];
			int b1 = x.first.second + dy[k];
			if (k == 0) {
				if (a + 1 <= n)
				{
					step1 = abs(A[a + 1][b] - A[a][b]);
					if (!visited[a + step1][b] && (a + step1 <= n) && step1)
					{
						q.push({{a + step1, b}, x.second + 1});
						visited[a + step1][b] = 1;
					}
				}
			} else if (k == 1) {
				if (b + 1 <= m)
				{
					step2 = abs(A[a][b + 1] - A[a][b]);
					if (!visited[a][b + step2] && (b + step2 <= m) && step2)
					{
						q.push({{a, b + step2}, x.second + 1});
						visited[a][b + step2] = 1;
					}
				}
			} else {
				if (a + 1 <= n && b + 1 <= m)
				{
					step3 = abs(A[a][b] - A[a + 1][b + 1]);
					if (!visited[a + step3][b + step3] && (a + step3 <= n) && (b + step3 <= m) && step3)
					{
						q.push({{a + step3, b + step3}, x.second + 1});
						visited[a + step3][b + step3] = 1;
					}
				}
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
	int t;
	cin >> t;
	while (t--) {
		cin >> n >> m;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				cin >> A[i][j];
			}
		}
		cout << BFS() << endl;
		memset(visited, 0, sizeof(visited));
		memset(A, 0, sizeof(A));
	}
	return 0;
}