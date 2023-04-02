#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int n, m;
char x[1005], a[1005];
void init() {
	a[1] = 'A';
	a[2] = 'B';
	a[3] = 'C';
}

int cnt[1005];

map<char, int>mp;

void Try(int i) {
	for (int j = 1; j <= 3; j++) {
		x[i] = a[j];
		mp[x[i]]++;
		if (i == m) {
			if (mp['A'] > 0 && mp['B'] > 0 && mp['C'] > 0 && mp['A'] <= mp['B'] && mp['B'] <= mp['C']) {
				for (int k = 1; k <= m; k++) {
					cout << x[k];
				}
				cout << endl;
			}
		} else Try(i + 1);
		mp[x[i]] --;
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
	cin >> n;
	for (int i = 3; i <= n; i++) {
		m = i;
		Try(1);
	}
	return 0;
}