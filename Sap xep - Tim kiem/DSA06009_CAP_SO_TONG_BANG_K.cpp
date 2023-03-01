#include <bits/stdc++.h>

using namespace std;

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int n, k;
		cin >> n >> k;
		vector<int> v;
		for (int i = 0; i < n; i++)
		{
			int x;
			cin >> x;
			v.push_back(x);
		}
		sort(v.begin(), v.end());
		int dem = 0;
		for (int i = 0; i < n; i++)
		{
			auto c = lower_bound(v.begin() + i + 1, v.end(), k - v[i]);
			auto b = upper_bound(v.begin() + i + 1, v.end(), k - v[i]);
			dem += b - c;
		}
		cout << dem << endl;
	}
}