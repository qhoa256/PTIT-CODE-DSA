#include <bits/stdc++.h>
#pragma gcc optimize("Ofast")
using namespace std;

using ll = long long;

int t, n;

struct qd
{
	ll x;
	string s;
	ll idex;
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
	cin >> t;
	while (t--)
	{
		cin >> n;
		vector<qd> v;
		map<int, bool> mp;
		map<string, bool> mp2;
		set<string> se;
		for (int i = 0; i < n; i++)
		{
			int x1;
			string s1;
			cin >> x1 >> s1;
			if (s1 == "00")
				continue;
			se.insert(s1);
			if (s1 == "11")
				mp[i] = true;
			qd tam;
			tam.x = x1;
			tam.s = s1;
			tam.idex = i;
			v.push_back(tam);
		}
		sort(v.begin(), v.end(), [](qd x, qd y)->bool{
			if (x.x != y.x) return x.x < y.x;
			else return x.s > y.s;
		});
		int res = -1, cnt = 0, cnt2 = 0;
		if (se.size() < 2 && se.count("11") == 0)
			cout << -1 << endl;
		else
		{
			int sum = 0;
			int sum2 = 0;
			if (mp.size())
			{
				for (auto x : v)
				{
					if (!mp2[x.s] && x.s != "11")
					{
						sum += x.x;
						cnt++;
						mp2[x.s] = true;
					}
					else
					{
						if (!mp2[x.s] && x.s == "11")
						{
							sum2 += x.x;
							mp2[x.s] = true;
						}
					}
				}
				if (cnt >= 2)
				{
					cout << min(sum, sum2) << endl;
				}
				else
					cout << sum2 << endl;
			}
			else
			{
				for (auto x : v)
				{
					if (!mp2[x.s] && x.s != "11")
					{
						sum += x.x;
						mp2[x.s] = true;
					}
				}
				cout << sum << endl;
			}
		}
	}
	return 0;
}