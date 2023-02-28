// Nguyen Huu Quang Hoa - B21DCCN379
#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
    {
        int n1, n2, n3;
        cin >> n1 >> n2 >> n3;
        map<ll, ll> mp;
        map<ll, ll> mp1, mp2, mp3;
        for (int i = 0; i < n1; i++)
        {
            ll x;
            cin >> x;
            mp[x] = 1;
            mp1[x]++;
        }
        for (int i = 0; i < n2; i++)
        {
            ll x;
            cin >> x;
            if (mp[x] == 1)
            {
                mp[x] = 2;
            }
            mp2[x]++;
        }
        for (int i = 0; i < n3; i++)
        {
            ll x;
            cin >> x;
            if (mp[x] == 2)
            {
                mp[x] = 3;
            }
            mp3[x]++;
        }
        int ok = 0;
        for (auto x : mp)
        {
            if (x.second == 3)
            {
                ok = 1;
                for (int i = 0; i < min({mp1[x.first], mp2[x.first], mp3[x.first]}); i++)
                {
                    cout << x.first << " ";
                }
            }
        }
        if (!ok)
            cout << -1 << endl;
        else
            cout << endl;
    }
    return 0;
}