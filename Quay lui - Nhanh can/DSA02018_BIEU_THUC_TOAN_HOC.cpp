#include <bits/stdc++.h>
#pragma gcc optimize("Ofast")
#define endl '\n'
using namespace std;

using ll = long long;

vector<int> a(5);
vector<vector<int>> boSo;
vector<vector<int>> boDau;
vector<int> dau(4);
vector<int> so(5);
vector<bool> vs(5, false);

void TrySo(int i)
{
	if (i == 5)
	{
		boSo.push_back(so);
		return;
	}
	for (int j = 0; j < 5; ++j)
	{
		if (!vs[j])
		{
			vs[j] = true;
			so[i] = a[j];
			TrySo(i + 1);
			vs[j] = false;
		}
	}
}

void TryDau(int i)
{
	if (i == 4)
	{
		boDau.push_back(dau);
		return;
	}
	for (int j = 1; j <= 3; ++j)
	{
		dau[i] = j;
		TryDau(i + 1);
	}
}

int cal(int a, int b, int o)
{
	switch (o)
	{
	case 1:
		return a + b;
	case 2:
		return a - b;
	case 3:
		return a * b;
	}
	return 0;
}

bool check(vector<int> so, vector<int> dau)
{
	return cal(cal(cal(cal(so[0], so[1], dau[0]), so[2], dau[1]), so[3], dau[2]), so[4], dau[3]) == 23;
}

void Solve()
{
	boSo.clear();
	boDau.clear();
	for (int &i : a)
		cin >> i;
	TrySo(0);
	TryDau(0);
	for (auto i : boSo)
	{
		for (auto j : boDau)
		{
			if (check(i, j) == true)
			{
				cout << "YES";
				return;
			}
		}
	}
	cout << "NO";
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
	while (t--) {
		Solve();
		cout << endl;
	}
	return 0;
}