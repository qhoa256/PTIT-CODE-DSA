#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int n, x[1005], a[1005];
void init() {
	a[1] = 2;
	a[2] = 3;
	a[3] = 5;
	a[4] = 7;
}

map<int,int> h;

void Try(int i) {
	for (int j = 1; j <= 4; j++) {
		x[i] = a[j];
		h[x[i]] ++;
		if (i == n) {
			if (h[2] > 0 && h[3] > 0 && h[5] > 0 && h[7] > 0 && x[n] != 2) {
				for (int k = 1; k <= n; k++) {
					cout << x[k];
				}
				cout << endl;
			}
		} else Try(i + 1);
		h[x[i]] --;
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
	Try(1);
	return 0;
}