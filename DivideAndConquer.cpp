#include <bits/stdc++.h>
#pragma gcc optimize("Ofast")
#define endl '\n'
using namespace std;

using ll = long long;

int t, n, x, ok;
string s;
vector<string>v;

void init() {
	s = string(n, '6');
}

void sinh() {
	int i = s.size() - 1;
	while (i >= 0 && s[i] == '8') {
		s[i] = '6';
		--i;
	}
	if (i == -1) ok = 0;
	else s[i] = '8';
}

void ktao() {
	for (int i = 1; i <= 15; i++) {
		ok = 1;
		n = i;
		init();
		while (ok) {
			string tmp = s;
			reverse(tmp.begin(), tmp.end());
			v.push_back(s + tmp);
			sinh();
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
	ktao();
	cin >> t;
	while (t--) {
		cin >> x;
		for (int i = 0; i < x; i++) {
			cout << v[i] << " ";
		}
		cout << endl;
	}
	return 0;
}