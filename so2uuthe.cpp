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

void init() {
	queue<string>q;
	q.push("0");
	q.push("1");
	q.push("2");
	while (1) {
		string top = q.front();
		q.pop();
		if (top.size() == n) break;
		if (check(top)) v.insert(stoll(top));
		q.push(top + "0");
		q.push(top + "1");
		q.push(top + "2");
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
	init();
	int t;
	cin >> t;
	while (t--) {
		int x;
		cin >> x;
		int dem = 0;
		for (auto h : v) {
			cout << h << " ";
			dem++;
			if (dem == x) break;
		}
		cout << endl;
	}
	return 0;
}