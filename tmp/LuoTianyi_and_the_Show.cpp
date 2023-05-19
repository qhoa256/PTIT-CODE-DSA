#include <bits/stdc++.h>
#define ll long long
#pragma GCC optimize("Ofast")
const ll mod = (ll)1e9 + 7;
#define endl "\n"
#define maxn 1000006
#define _oo LLONG_MIN
#define oo LLONG_MAX - 9
#define bit(x, i) ((x >> i) & 1)
#define all(v) v.begin(), v.end()
#define ms(a) memset(a, 0, sizeof(a))
#define faster()                  \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);
using namespace std;
ll n, a[1000001], b[1000001];
vector<string> v;
void back_track(ll i, ll pos, ll sum)
{
	if (i <= n - 1)
	{
		for (ll j = pos; j < n; j++)
		{
			b[i] = a[j];
			sum += b[i];
			if (sum % 2 == 1)
			{
				string tam = "";
				for (ll k = 0; k <= i; k++)
					tam += to_string(b[k]) + " ";
				tam.pop_back();
				v.push_back(tam);
			}
			back_track(i + 1, j + 1, sum);
			sum -= b[i];
		}
	}
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	faster();
	ll t;
	cin >> t;
	while (t--)
	{
		cin >> n;
		for (ll i = 0; i < n; i++)
			cin >> a[i];
		sort(a, a + n, greater<ll>());
		back_track(0, 0, 0);
		sort(all(v));
		for (auto &x : v)
			cout << x << endl;
		v.clear();
		ms(a);
		ms(b);
	}
	return 0;
}