#include <bits/stdc++.h>
#pragma gcc optimize("Ofast")
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
	deque<int>dq;
	while (t--) {
		string s;
		getline(cin, s);
		string tmp;
		vector<string>v;
		stringstream ss(s);
		while (ss >> tmp) {
			v.push_back(tmp);
		}
		if (v[0] == "PUSHFRONT") {
			dq.push_front(stoi(v[1]));
		} else if (v[0] == "PRINTFRONT") {
			if (!dq.empty()) {
				cout << dq.front() << endl;
			} else {
				cout << "NONE\n";
			}
		} else if (v[0] == "POPFRONT") {
			if (!dq.empty()) {
				dq.pop_front();
			}
		} else if (v[0] == "PUSHBACK") {
			dq.push_back(stoi(v[1]));
		} else if (v[0] == "PRINTBACK") {
			if (!dq.empty()) {
				cout << dq.back() << endl;
			} else {
				cout << "NONE\n";
			}
		} else {
			if (!dq.empty()) {
				dq.pop_back();
			}
		}
	}
	return 0;
}