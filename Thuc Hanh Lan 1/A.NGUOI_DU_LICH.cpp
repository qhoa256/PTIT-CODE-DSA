#include <bits/stdc++.h>

using namespace std;

using ll = long long;
int n, c[1005][1005], cmin = INT_MAX, visited[1005], x[1005], ans = INT_MAX;
vector<vector<int>>res;

void Try(int i, int sum) {
	for (int j = 2; j <= n; j++) {
		if (!visited[j]) {
			x[i] = j;
			visited[j] = 1;
			sum += c[x[i - 1]][x[i]];
			if (i == n) {
				if (ans > sum + c[x[i]][1]) {
					ans = sum + c[x[i]][1];
					vector<int>tmp;
					for (int k = 1; k <= i; k++) {
						tmp.push_back(x[k]);
					}
					tmp.push_back(x[1]);
					res.push_back(tmp);
				}
			} else if (sum + (n - i - 1)*cmin < ans) Try(i + 1, sum);
			visited[j] = 0;
			sum -= c[x[i - 1]][x[i]];
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
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> c[i][j];
			cmin = min(cmin, c[i][j]);
		}
	}
	x[1] = 1;
	Try(2, 0);
	cout << "(";
	int qhoa = res.size() - 1;
	for (int i = 0; i < res[qhoa].size(); i++) {
		cout << res[qhoa][i];
		if (i != res[qhoa].size() - 1)
			cout << ",";
	}
	cout << ")\n";
	cout << ans;
	return 0;
}