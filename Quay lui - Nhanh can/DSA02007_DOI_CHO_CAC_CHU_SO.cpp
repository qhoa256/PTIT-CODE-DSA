#include<bits/stdc++.h>
using namespace std;

using ll = long long;
const int mod = 1e9 + 7;
int k;
string s;
void Try(string s, string &maxx, int idx) {
	if (k == 0) return;
	int n = s.size();
	char tmp = s[idx];
	for (int i = idx + 1; i < n; i++) {
		if (tmp < s[i]) tmp = s[i];
	}
	if (tmp != s[idx]) --k;
	for (int i = n - 1; i >= idx; i--) {
		if (s[i] == tmp) {
			swap(s[i], s[idx]);
			if (s > maxx) maxx = s;
			Try(s, maxx, idx + 1);
			swap(s[i], s[idx]);
		}
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int t; cin >> t;
	while (t--) {
		cin >> k >> s;
		string ans = s;
		Try(s, ans, 0);
		cout << ans << endl;
	}
}