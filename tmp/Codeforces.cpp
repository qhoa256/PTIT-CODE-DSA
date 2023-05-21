#include <bits/stdc++.h>
#pragma gcc optimize("Ofast")
#define endl '\n'
using namespace std;

using ll = long long;

int t, n;
string s;
void solve() {
	set<string> se;
	for (ll i = 0; i < s.size() - 1; i++)
	{
		string tmp = "";
		tmp += s[i];
		tmp += s[i + 1];
		se.insert(tmp);
	}
	cout << se.size() << endl;
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
	while (t--)
	{
		cin >> n >> s;
		solve();
	}
	return 0;
}