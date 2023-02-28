#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int t, n, p, s, a[1005];
vector<vector<int>>res;
vector<int>nto;
bool prime(int n) {
	for (int i = 2; i <= sqrt(n); i++) {
		if (n % i == 0) return false;
	}
	return n > 1;
}

void nhap() {
	for (int i = p + 1; i <= s; i++) {
		if (prime(i))
			nto.push_back(i);
	}
}

void Try(int i, int sum, int pos) {
	if (i == n && sum == s) {
		vector<int>tmp(a, a + n);
		res.push_back(tmp);
	}
	for (int j = pos; j < nto.size(); j++) {
		if (sum + nto[j] <= s) {
			a[i] = nto[j];
			Try(i + 1, sum + nto[j], j + 1);
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
		cin >> n >> p >> s;
		nto.clear();
		res.clear();
		nhap();
		Try(0, 0, 0);
		cout << res.size() << endl;
		for (int i = 0; i < res.size(); i++) {
			for (auto x : res[i]) cout << x << " ";
			cout << endl;
		}
	}
	return 0;
}
