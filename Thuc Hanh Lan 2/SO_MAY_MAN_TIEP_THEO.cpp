#include <bits/stdc++.h>

using namespace std;

using ll = long long;

vector<ll>v;

ll a, b;
void init() {
	queue<string>q;
	q.push("4");
	q.push("7");
	while (1) {
		string top = q.front();
		q.pop();
		if (top.size() == 19) break;
		v.push_back(stoll(top));
		q.push(top + "4");
		q.push(top + "7");
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
	cin >> a >> b;
	ll sum = 0;
	for (int i = a; i <= b; i++) {
		auto it = lower_bound(v.begin(), v.end(), i);
		sum += *it;
	}
	cout << sum;
	return 0;
}