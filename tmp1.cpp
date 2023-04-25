#include <bits/stdc++.h>
using namespace std;

using ll = long long;
int prime[10005];
int cnt[10005];

void sang()
{
	for (int i = 0; i <= 10000; ++i) prime[i] = 1;
	prime[0] = prime[1] = 0;
	for (int i = 2; i <= sqrt(10000); ++i)
	{
		if (prime[i])
		{
			for (int j = i * i; j <= 10000; j += i)
			{
				prime[j] = 0;
			}
		}
	}
}

int main(int argc, char **argv)
{
	int t; cin >> t;
	sang();
	while (t--)
	{
		string s, t; cin >> s >> t;
		queue<pair<string, int>> q;
		q.push({s, 0});
		memset(cnt, 0, sizeof(cnt));

		while (1)
		{
			pair<string , int> x = q.front();
			q.pop();
			if (x.first == t)
			{
				cout << x.second << endl;
				break;
			}
			for (int i = 0; i < x.first.size(); ++i)
			{
				string tmp = x.first;
				int k;
				if (i == 0) k = 1;
				else k = 0;
				for (int j = k; j < 10; ++j)
				{
					tmp[i] = j + '0';
					int y = stoi(tmp);
					if (prime[y] && !cnt[y])
					{
						q.push({tmp, x.second + 1});
						cnt[y] = 1;
					}
				}
			}
		}
	}
}