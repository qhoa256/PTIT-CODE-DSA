#include <bits/stdc++.h>
#pragma gcc optimize("Ofast")
#define endl '\n'
using namespace std;

using ll = long long;

int t, n, ok, a[1005];
string s;
void init() {
	s = string(n, 'A');
	ok = 1;
}

void sinh() {
	int i = n - 1;
	while (i >= 0 && s[i] == 'H') {
		s[i] = 'A';
		--i;
	}
	if (i == -1) ok = 0;
	else s[i] = 'H';
}

bool check() {
	if (s[0] != 'H' || s[n - 1] != 'A') return false;
	for (int i = 1; i < n; i++) {
		if (s[i] == 'H' && s[i - 1] == 'H') return false;
	}
	return true;
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
		cin >> n;
		init();
		while (ok) {
			if (check())
				cout << s << endl;
			sinh();
		}
	}
	return 0;
}