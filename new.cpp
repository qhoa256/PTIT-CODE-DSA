#include <bits/stdc++.h>
#pragma gcc optimize("Ofast")
using namespace std;

using ll = long long;

int n, m, d[10000], c[10000], ts[10000];
int vs[100], t[100];


void KRUSKAL(int a[][])
{
	for (int i = 1; i <= m - 1, i++)
		for (int j = i + 1; j <= m, j++)
			if (ts[i] > ts[j])
			{
				int tg = ts[i];
				ts[i] = ts[j];
				ts[j] = tg;

				tg = d[i];
				d[i] = d[j];
				d[j] = tg;

				tg = c[i];
				c[i] = c[j];
				c[j] = tg;
			}
	int wt = 0, k = 0;
	for (int i = 1; i <= n; i++)
		vs[i] = 0;
	for (int i = 1; i <= m; i++)
	{
		if (!(vs[d[i]] != 0 && vs[d[i]] == vs[c[i]]))
		{
			k++;
			t[k] = i;
			wt = wt + ts[i];
			if (k == n - 1)
			{
				cout << wt << endl;
				for (j = 1; j <= k; j++)
					cout << d[t[j]] << " " << c[t[j]] << endl;
				return;
			}
			int u = d[i], v = c[i];
			if (vs[u] == 0 && vs[v] == 0)
			{
				vs[u] = k;
				vs[v] = k;
			}
			else if (vs[u] == 0 && vs[v] != 0)
				vs[u] = vs[v];

			else if (vs[u] != 0 && vs[v] == 0)
				vs[v] = vs[u];

			else if (vs[u] < vs[v])
			{
				tg = vs[v];
				for (j = 1; j <= n; j++)
					if (vs[j] == tg)
						vs[j] = vs[u];
			}
			else if (vs[v] < vs[u])
			{
				tg = vs[u];
				for (j = 1; j <= n; j++)
					if (vs[j] == tg)
						vs[j] = vs[v];
			}
		}
	}
	cout << "Khong co cay khung" << endl;
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
	return 0;
}