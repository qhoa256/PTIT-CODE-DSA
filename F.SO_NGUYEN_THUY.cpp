#include <bits/stdc++.h>

using namespace std;

using ll = long long;

vector<string>v;

void init() {
	queue<string>q;
	q.push("4");
	q.push("5");
	while (1) {
		string top = q.front();
		q.pop();
		if (top.size() == 10) break;
		v.push_back(top);
		string tmp = top;
		reverse(tmp.begin(), tmp.end());
		q.push(top + tmp);
		q.push(top + top);
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
	int t;
	cin >> t;
	while (t--) {
		for(auto x:v){
			cout<<x<<" ";
		}
		cout << endl;
	}
	return 0;
}