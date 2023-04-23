#include <bits/stdc++.h>

using namespace std;

using ll = long long;

struct knapsack {
	int weight, value;
	double fraction;
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
	while (t--) {
		int n, v;
		cin >> n >> v;
		knapsack ks[n];
		for (int i = 0; i < n; i++) {
			cin >> ks[i].weight >> ks[i].value;
			ks[i].fraction = 1.0 * ks[i].weight / 1.0 * ks[i].value;
		}
		sort(ks, ks + n, [](knapsack a, knapsack b)->bool{
			return a.fraction > b.fraction;
		});
		double sum_value = 0, sum_weight = 0;
		int i = 0;
		while (sum_weight < v) {
			sum_weight += ks[i].weight;
			sum_value += ks[i].value;
			i++;
		}
		if (sum_weight > v) sum_weight -= ks[i - 1].value;
		cout << fixed << setprecision(2) << sum_value << endl;
	}
	return 0;
}