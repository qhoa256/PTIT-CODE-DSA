#include <bits/stdc++.h>
#pragma gcc optimize("Ofast")
using namespace std;

using ll = long long;

int prime[10005];
int cnt[10005];
void sieve() {
	for (int i = 0; i <= 10000; i++) {
		prime[i] = 1;
	}
	prime[0] = prime[1] = 0;
	for (int i = 0; i <= sqrt(10000); i++) {
		if (prime[i]) {
			for (int j = i * i; j <= 10000; j += i) {
				prime[j] = 0;
			}
		}
	}
}

int BFS(string s, string t) {
	queue<pair<string, int>>q;
	q.push({s, 0});
	cnt[stoi(s)] = 1;
	while (!q.empty()) {
		auto x = q.front();
		q.pop();
		string tmp = x.first;
		if (tmp == t) return x.second;
		for (int i = 0; i < 4; i++) {
			if (i == 0) {
				for (int j = 1; j < 10; j++) {
					tmp[i] = j + '0';
					if (!cnt[stoi(tmp)] && prime[stoi(tmp)]) {
						q.push({tmp, x.second + 1});
						cnt[stoi(tmp)] = 1;
					}
				}
			} else {
				for (int j = 0; j < 10; j++) {
					tmp[i] = j + '0';
					if (!cnt[stoi(tmp)] && prime[stoi(tmp)]) {
						q.push({tmp, x.second + 1});
						cnt[stoi(tmp)] = 1;
					}
				}
			}
			tmp = x.first;
		}
	}
	return 0;
}
int test;
string s, t;
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	sieve();
	cin >> test;
	while (test--) {
		cin >> s >> t;
		if (s > t) swap(s, t);
		cout << BFS(s, t) << endl;
		memset(cnt, 0, sizeof(cnt));
	}
	return 0;
}