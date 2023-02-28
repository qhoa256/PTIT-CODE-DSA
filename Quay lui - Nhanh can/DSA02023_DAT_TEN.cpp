#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int n, k, x[1005];
vector<string>v;

void in() {
	for (int i = 1; i <= k; i++) {
		cout << v[x[i]] << " ";
	}
	cout << endl;
}
void Try(int i) {
	for (int j = x[i - 1] + 1; j <= n - k + i; j++) {
		x[i] = j;
		if (i == k) {
			in();
		} else Try(i + 1);
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
	set<string>se;
	for (int i = 0; i < n; i++) {
		string tmp;
		cin >> tmp;
		se.insert(tmp);
	}
	v.push_back("Quang Hoa");
	for (auto x : se) {
		v.push_back(x);
	}
	n = v.size() - 1;
	Try(1);
	return 0;
}