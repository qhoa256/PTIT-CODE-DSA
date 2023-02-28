#include <bits/stdc++.h>

using namespace std;

using ll = long long;

char c;
int n;
char x[1005];

void Try(int i, char h) {
	for (char j = h; j <= c; j++) {
		x[i] = j;
		if (i == n) {
			for (int k = 1; k <= n; k++)
				cout << x[k];
			cout << endl;
		} else Try(i + 1, j);
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
	cin >> c >> n;
	Try(1, 'A');
	return 0;
}