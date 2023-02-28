#include <bits/stdc++.h>

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
	queue<int>q;
	int t;
	cin >> t;
	cin.ignore();
	string s;
	while (t--) {
		getline(cin, s);
		if (s.substr(0, 4) == "PUSH") {
			stringstream ss(s);
			string tmp;
			vector<string>v;
			while (ss >> tmp) {
				v.push_back(tmp);
			}
			q.push(stoi(v[v.size() - 1]));
		} else if (s == "PRINTFRONT") {
			if (!q.empty()) {
				cout << q.front() << endl;
			} else {
				cout << "NONE\n";
			}
		} else {
			if (!q.empty()) {
				q.pop();
			}
		}
	}
	return 0;
}