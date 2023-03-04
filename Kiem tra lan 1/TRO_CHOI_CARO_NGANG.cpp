#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int t, n;
char c[1005];
char x;
string str = "XO";
vector<string>v;

bool check() {
	int maxo = 0, maxx = 0;
	int reso = 0, resx = 0;
	for (int i = 1; i <= n; i++) {
		if (c[i] == 'X') {
			maxx++;
		} else {
			resx = max(resx, maxx);
			maxx = 0;
		}
		if (c[i] == 'O') {
			maxo++;
		} else {
			reso = max(reso, maxo);
			maxo = 0;
		}
	}
	if (c[n] == 'X') {
		resx = max(resx, maxx);
	}
	if (c[n] == 'O') {
		reso = max(reso, maxo);
	}
	if (x == 'O') return reso > resx && reso >= 5;
	else return resx > reso && resx >= 5;
}
void Try(int i, string s) {
	for (int j = 0; j <= 1; j++) {
		c[i] = str[j];
		s += str[j];
		if (i == n) {
			if (check()) {
				v.push_back(s);
			}
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
	cin >> t;
	while (t--) {
		cin >> n >> x;
		Try(1, "");
		sort(v.begin(), v.end());
		for (auto x : v) cout << x << endl;
		v.clear();
	}
	return 0;
}