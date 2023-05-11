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
struct qd
{
    ll x;
    string s;
    ll idex;
};
bool cmp(qd x, qd y)
{
    if (x.x != y.x)
        return x.x < y.x;
    return x.s > y.s;
}
int main()
{
    faster();
    ll t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        vector<qd> v;
        map<ll, bool> mp;
        map<string, bool> mp2;
        set<string> se;
        for (ll i = 0; i < n; i++)
        {
            ll x1;
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
        sort(all(v), cmp);
        ll res = -1, cnt = 0, cnt2 = 0;
        if (se.size() < 2 && se.count("11") == 0)
            cout << -1 << endl;
        else
        {
            ll sum = 0;
            ll sum2 = 0;
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
}