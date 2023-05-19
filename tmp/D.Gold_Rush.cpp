#include <bits/stdc++.h>
#pragma gcc optimize("Ofast")
using namespace std;

using ll = long long;

int t, n, m;

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
		cin >> n >> m;
		int ok = 0;
		queue<int> qe;
		qe.push(n);
		while (!qe.empty())
		{
			int top = qe.front();
			qe.pop();
			if (top == m) {
				ok = 1;
				break;
			}
			if (top % 3 == 0)
			{
				int tam = top / 3;
				qe.push(tam);
				qe.push(tam * 2);
			}
		}
		if (ok) cout << "YES\n";
		else cout << "NO\n";
	}
	return 0;
}