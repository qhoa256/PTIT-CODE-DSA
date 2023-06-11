#include<bits/stdc++.h>
using namespace std;
using ll = long long;

void greater_right(int a[], int n, int d[]) {
	stack<int>st;
	for (int i = 0; i < n; i++) {
		while (!st.empty() && a[i] > a[st.top()]) {
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

void smaller_right(int a[], int n, int d[]) {
	stack<int>st;
	for (int i = 0; i < n; i++) {
		while (!st.empty() && a[i] < a[st.top()]) {
			d[st.top()] = a[i];
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
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		int a[n];
		for (auto &x : a) cin >> x;
		int S[n] = {0}, G[n] = {0};
		greater_right(a, n, G);
		smaller_right(a, n, S);
		for (int i = 0; i < n; i++) {
			if (G[i] == -1) cout << "-1 ";
			else cout << S[G[i]] << " ";
		}
		cout << endl;
	}
	return 0;
}