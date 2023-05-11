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
ll cnt[maxn];
ll n, m;
int main()
{
    faster();
    ll t;
    cin >> t;
    while (t--)
    {
        cin >> n >> m;
        set<ll> se;
        multiset<ll> se2;
        map<ll, ll> mp;
        for (ll i = 0; i < m; i++)
        {
            ll x, y;
            cin >> x >> y;
            cnt[x]++;
            cnt[y]++;
        }
        for (ll i = 1; i <= n; i++)
        {
            se.insert(cnt[i]);
            se2.insert(cnt[i]);
            mp[cnt[i]]++;
        }
        vector<ll> v(all(se));
        ll max1 = -1, max2 = -1, cnt2 = 0;
        max1 = v[v.size() - 1];
        max2 = v[v.size() - 2];
        if (se.size() >= 3)
        {
            if (mp[max1] != 1)
            {
                cout << max2 << " " << max1 - 1 << endl;
            }
            else
            {
                cout << max1 << " " << max2 - 1 << endl;
            }
        }
        else
            cout << max1 << " " << max1 - 1 << endl;
        ms(cnt);
    }
}