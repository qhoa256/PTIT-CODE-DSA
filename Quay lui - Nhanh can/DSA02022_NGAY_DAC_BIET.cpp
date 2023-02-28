#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int x[1005];

vector<string>v;
set<string>se;

void Try(int i) {
	for (int j = 0; j <= 2; j ++) {
		if (j == 0 || j == 2) {
			x[i] = j;
			if (i == 8) {
				string s = "";
				for (int i = 1; i <= 8; i++) {
					s += to_string(x[i]);
				}
				if ((s[0] != '0' || s[1] != '0') && (s[2] == '0' && s[3] != '0') && s[4] == '2') {
					s.insert(2, "/");
					s.insert(5, "/");
					v.push_back(s);
				}
			} else Try(i + 1);
		}
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
	Try(1);
	sort(v.begin(), v.end());
	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << endl;
	}
	return 0;
}