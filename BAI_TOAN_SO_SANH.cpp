#include <bits/stdc++.h>
#pragma gcc optimize("Ofast")
#define endl '\n'
using namespace std;

using ll = long long;

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	cin.ignore();
	int cnt1 = 0, cnt2 = 0;
	while (t--) {
		string s;
		getline(cin, s);
		stringstream ss(s);
		string tmp;
		vector<string>v;
		while (ss >> tmp) {
			v.push_back(tmp);
		}
		
	}
	return 0;
}