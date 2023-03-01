#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int a, b, n;
char x[1005], h[1005];
vector<ll>v;

void init() {
	h[1] = '4';
	h[2] = '7';
}

void Try(int i, string s) {
	for (int j = 1; j <= 2; j++) {
		x[i] = h[j];
		s += x[i];
		if (i == n) {
			v.push_back(stoll(s));
		} else Try(i + 1, s);
		s.pop_back();
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
	for (int i = 1; i <= 10; i++) {
		n = i;
		Try(1, "");
	}
	cin >> a >> b;
	ll sum = 0;
	for (int i = a; i <= b; i++) {
		for (auto x : v) {
			if (x >= i) {
				sum += x;
				break;
			}
		}
	}
	cout << sum;
	return 0;
}