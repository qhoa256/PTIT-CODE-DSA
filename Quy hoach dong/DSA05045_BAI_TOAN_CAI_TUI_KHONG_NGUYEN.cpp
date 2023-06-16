#include <bits/stdc++.h>
#pragma gcc optimize("Ofast")
#define endl '\n'
using namespace std;

using ll = long long;

struct X
{
	int value, weight;
	float x;
};

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
		int n, k;
		cin >> n >> k;
		vector<X>v;
		X M[n];
		for (int i = 0; i < n; i++) {
			cin >> M[i].weight >> M[i].value;
			M[i].x = (float)M[i].weight / M[i].value;
		}
		sort(M, M + n, [](X a, X b)->bool{
			return a.x > b.x;
		});
		int sum_value = 0;
		float sum_weight = 0;
		int c = 0;
		for (int i = 0; i < n; i++)
		{
			if (sum_value <= k)
			{
				sum_value += M[i].value;
				sum_weight += M[i].weight;
				c = i;
			}
		}
		if (sum_value > k)
			sum_weight -= (float)(sum_value - k) * M[c].x;
		cout << setprecision(2) << fixed << sum_weight << endl;
	}
	return 0;
}