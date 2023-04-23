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
	int n, k;
	cin >> n >> k;
	int a[n];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	deque<int> dq;
	for (int i = 0; i < k; i++) {
		while ((!dq.empty()) && a[i] >= a[dq.back()])
			dq.pop_back();
		dq.push_back(i);
	}
	for (int i = k; i < n; i++) {
		cout << a[dq.front()] << " ";
		while ((!dq.empty()) && dq.front() <= i - k)
			dq.pop_front();
		while ((!dq.empty()) && a[i] >= a[dq.back()])
			dq.pop_back();
		dq.push_back(i);
	}
	cout << a[dq.front()];
	return 0;
}