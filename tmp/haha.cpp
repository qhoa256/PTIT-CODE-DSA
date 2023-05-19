#include <bits/stdc++.h>
using namespace std;

int main()
{
    faster();
    ll t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        set<ll> se;
        for (ll i = 1; i <= n; i++)
        {
            ll x;
            cin >> x;
            if (abs(x - i) != 0)
                se.insert(abs(x - i));
        }
        ll res = 0;
        for (auto &x : se)
            res = __gcd(x, res);
        cout << res << endl;
    }
}