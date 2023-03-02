#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int n, k, X[1005], a[1005];

vector<string>v;


void Try(int i, int pos) {
	for (int j = pos; j <= n; j++) {
		X[i] = a[j];
		if (i == k) {
			string tmp = "";
			for (int x = 1; x <= k; x++) {
				tmp += to_string(X[x]) + " ";
			}
			tmp.pop_back();
			v.push_back(tmp);
		} else Try(i + 1, j + 1);
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
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	Try(1, 1);
	sort(v.begin(), v.end());
	for (auto x : v) {
		cout << x << endl;
	}
	return 0;
}