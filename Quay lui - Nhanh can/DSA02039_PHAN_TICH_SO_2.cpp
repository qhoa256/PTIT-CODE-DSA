#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int t, n, x[1001];

vector<vector<int>> v;

void Try(int i, int pos, int sum)
{
	for (int j = pos; j >= 1; j--)
	{
		x[i] = j;
		if (j == sum)
		{
			vector<int> tmp(x + 1, x + i + 1);
			v.push_back(tmp);
		}
		else if (j < sum)
			Try(i + 1, j, sum - j);
	}
}
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin >> t;
	while (t--)
	{
		cin >> n;
		Try(1, n, n);
		cout << v.size() << endl;
		for (int i = 0; i < v.size(); i++)
		{
			cout << "(";
			for (int j = 0; j < v[i].size(); j++)
			{
				cout << v[i][j];
				if (j != v[i].size() - 1)
					cout << " ";
			}
			cout << ") ";
		}
		cout << endl;
		memset(x, 0, sizeof(x));
		v.clear();
	}
	return 0;
}