#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int n, m; int a[1000][1000];
vector<int> s[1000];
void check() {
	for (int j = 0; j < m; j++) {
		int dem = 0;
		for (int i = 0; i < n; i++) {
			if (a[i][j] == 1) dem++;
			else dem = 0;
			s[i].push_back(dem);
		}
	}
}
void right(vector<int>&v, int d[]) {
	stack<int>st;
	for (int i = 0; i < m; i++) {
		while (!st.empty() && v[i] < v[st.top()]) {
			d[st.top()] = i;
			st.pop();
		}
		st.push(i);
	}
	while (!st.empty()) {
		d[st.top()] = m;
		st.pop();
	}
}
void left(vector<int>&v, int d[]) {
	stack<int>st;
	for (int i = m - 1; i >= 0; i--) {
		while (!st.empty() && v[i] < v[st.top()]) {
			d[st.top()] = i;
			st.pop();
		}
		st.push(i);
	}
	while (!st.empty()) {
		d[st.top()] = -1;
		st.pop();
	}
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int t; cin >> t;
	while (t--) {
		cin >> n >> m;
		for (int i = 0; i < m; i++) s[i].clear();
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cin >> a[i][j];
			}
		}
		check();
		ll ans = 0;
		for (int i = 0; i < n; i++) {
			int r[m], l[m];
			right(s[i], r);
			left(s[i], l);
			for (int j = 0; j < m; j++) {
				ll dt = s[i][j] * (r[j] - l[j] - 1);
				ans = max(ans, dt);
			}
		}
		cout << ans << endl;
	}
}