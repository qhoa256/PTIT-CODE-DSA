#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int t, n, k, x[1005];
string s;
vector<string>v;
void Try(int i, string tmp) {
	for (int j = x[i - 1] + 1; j <= n - k + i; j++) {
		x[i] = j;
		tmp += s[x[i] - 1];
		if (i == k) {
			v.push_back(tmp);
		} else Try(i + 1, tmp);
		tmp.pop_back();
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
		cin >> n >> s;
		for (int i = 1; i <= n; i++) {
			k = i;
			Try(1, "");
		}
		sort(v.begin(), v.end());
		for (auto x : v) {
			cout << x << " ";
		}
		cout << endl;
		v.clear();
	}
	return 0;
}