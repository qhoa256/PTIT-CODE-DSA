#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int n, w, ok = 1;
int x[1005];
void init() {
	for (int i = 1; i <= n; i++) x[i] = 0;
}

void sinh() {
	int i = n;
	while (i >= 1 && x[i] == 1) {
		x[i] = 0;
		--i;
	}
	if (i == 0) ok = 0; else x[i] = 1;
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
	cin >> n >> w;
	int C[n + 1], A[n + 1];
	for (int i = 1; i <= n; i++) {
		cin >> C[i];
	}
	for (int i = 1; i <= n; i++) {
		cin >> A[i];
	}
	init();
	vector<vector<int>>opt;
	int res = 0;
	while (ok) {
		int value = 0, weight = 0;
		for (int i = 1; i <= n; i++) {
			value += C[i] * x[i];
			weight += A[i] * x[i];
		}
		if (weight <= w) {
			if (res < value) {
				res = value;
				vector<int>tmp(x + 1, x + n + 1);
				opt.push_back(tmp);
			}
		}
		sinh();
	}
	cout << res << endl;
	for (auto x : opt[opt.size() - 1]) cout << x << " ";
	return 0;
}