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
	int q;
	cin >> q;
	cin.ignore();
	while (q--) {
		string s;
		cin >> s;
		stringstream ss(s);
		string tmp;
		vector<string>v;
		while (ss >> tmp) {
			v.push_back(tmp);
		}
		deque<int, int>dq;
		if (v[0] == "PUSHFRONT") {
			dq.push_front(stoi(v[1]));
		} else if (v[0] == "PRINTFRONT") {
			if (!dq.empty()) {
				cout << dq.front() << endl;
			} else {
				cout << "NONE\n";
			}
		}
	}
	return 0;
}