#include <bits/stdc++.h>
#pragma gcc optimize("Ofast")
#define endl '\n'
using namespace std;

using ll = long long;

vector<ll>v[100005];
ll t, n, m;
ll a[1005][1005];
ll l[100005], r[100005];

void right(vector<ll>a, ll n, ll d[]) {
	stack<ll>st;
	for (ll i = 0; i < n; i++) {
		while (!st.empty() && a[i] < a[st.top()]) {
			d[st.top()] = i;
			st.pop();
		}
		st.push(i);
	}
	while (!st.empty()) {
		d[st.top()] = n;
		st.pop();
	}
}


void left(vector<ll>a, ll n, ll d[]) {
	stack<ll>st;
	for (ll i = n - 1; i >= 0; i--) {
		while (!st.empty() && a[i] < a[st.top()]) {
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

void init() {
	for (ll j = 0; j < m; j++) {
		ll cnt = 0;
		for (ll i = 0; i < n; i++) {
			if (a[i][j] == 0) cnt = 0;
			else cnt++;
			v[i].push_back(cnt);
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
	cin >> t;
	while (t--) {
		cin >> n >> m;
		for (ll i = 0; i < n; i++) {
			for (ll j = 0; j < m; j++) {
				cin >> a[i][j];
			}
		}
		init();
		ll res = -1e9;
		for (ll i = 0; i < n; i++) {
			memset(l, 0, sizeof(l));
			memset(r, 0, sizeof(r));
			right(v[i], v[i].size(), r);
			left(v[i], v[i].size(), l);
			for (ll k = 0; k < v[i].size(); k++) {
				ll tmp = 1ll * v[i][k] * (r[k] - l[k] - 1);
				res = max(res, tmp);
			}
		}
		cout << res << endl;
		for (ll i = 1; i <= n; i++) {
			v[i].clear();
		}
	}
	return 0;
}