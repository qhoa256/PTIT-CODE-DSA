#include <bits/stdc++.h>

using namespace std;

using ll = long long;

set<ll>v;
int n;
bool check(string s) {
	int cnt = 0;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == '2') cnt++;
	}
	return cnt > s.size() / 2;
}

void Try(string s) {
	if (s.size() < n) {
		if (check(s))
			v.insert(stoll(s));
		Try(s + "0");
		Try(s + "1");
		Try(s + "2");
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
	n = 10;
	Try("");
	int t;
	cin >> t;
	while (t--) {
		int x;
		cin >> x;
		int dem = 0;
		for (auto y : v) {
			cout << y << " ";
			dem++;
			if (dem == x) break;
		}
		cout << endl;
	}
	return 0;
}