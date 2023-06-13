#include <bits/stdc++.h>
#pragma gcc optimize("Ofast")
#define endl '\n'
using namespace std;

using ll = long long;

double distance(pair<double, double> a, pair<double, double> b)
{
	return sqrt((a.first - b.first) * (a.first - b.first) + (a.second - b.second) * (a.second - b.second));
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
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		double ans = 1e9;
		vector<pair<double, double>> a(n), b(n);
		for (int i = 0; i < n; i++)
		{
			cin >> a[i].first >> a[i].second;
			b[i].second = a[i].first;
			b[i].first = a[i].second;
		}
		sort(a.begin(), a.end());
		sort(b.begin(), b.end());
		for (int i = 1; i < n; i++)
		{
			ans = min(ans, distance(a[i], a[i - 1]));
			ans = min(ans, distance(b[i], b[i - 1]));
		}
		cout << fixed << setprecision(6) << ans << endl;
	}
	return 0;
}