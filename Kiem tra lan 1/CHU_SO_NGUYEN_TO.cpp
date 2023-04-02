#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int n, x[1005];
string a[1005], m;
void init() {
	a[1] = 'A';
	a[2] = 'B';
	a[3] = 'C';
}

map<char,int>mp;

void Try(int i) {
	for (int j = 1; j <= 3; j++) {
		x[i] = a[j];
		cnt[x[i]] ++;
		if (i == m) {
			if (mp['A'] > 0 && mp['B'] > 0 && mp['C'] > 0 && cnt[7] > 0 && x[m] != 2) {
				for (int k = 1; k <= m; k++) {
					cout << x[k];
				}
				cout << endl;
			}
		} else Try(i + 1);
		cnt[x[i]] --;
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
	for (int i = 4; i <= n; i++) {
		m = i;
		Try(1);
		//memset(cnt, 0, sizeof(cnt));
	}
	return 0;
}