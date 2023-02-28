#include <bits/stdc++.h>

using namespace std;

using ll = long long;
int Min;

int t, n;

void Try(int n, int dem) {
	if (dem > Min) return;
	if (n == 1) {
		Min = min(Min, dem);
		return;
	}
	if (n % 2 == 0) {
		Try(n / 2, dem + 1);
	}
	if (n % 3 == 0) {
		Try(n / 3, dem + 1);
	}
	Try(n - 1, dem + 1);
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
		Min = INT_MAX;
		cin >> n;
		Try(n, 0);
		cout << Min << endl;
	}
	return 0;
}