#include <bits/stdc++.h>

using namespace std;

using ll = long long;

void TowerHN(int n, char a, char b, char c) {
	if (n == 1) {
		cout << a << " -> " << c << endl; return;
	}
	TowerHN(n - 1, a, c, b);
	cout << a << " -> " << c << endl;
	TowerHN(n - 1, b, a, c);
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
	int n;
	cin >> n;
	TowerHN(n, 'A', 'B', 'C');
	return 0;
}