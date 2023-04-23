#include <bits/stdc++.h>

using namespace std;

using ll = long long;

vector<string>v;

void init() {
	queue<string>q;
	q.push("4");
	q.push("5");
	while (1) {
		string top = q.front();
		q.pop();
		string tmp = top;
		reverse(tmp.begin(), tmp.end());
		string x = "";
		x += top + tmp;
		if (x != "45" && x != "54") {
			v.push_back(x);
		}
		if (v.size() > 10000) break;
		q.push(top + "4");
		q.push(top + "5");
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
	init();
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		for (int i = 0; i < n; i++) {
			cout << v[i] << " ";
		}
		cout << endl;
	}
	return 0;
}