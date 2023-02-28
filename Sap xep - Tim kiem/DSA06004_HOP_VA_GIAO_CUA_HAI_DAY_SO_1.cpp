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
        int n, m;
        cin >> n >> m;
        int a[n], b[m];
        map<int, int> mp;
        set<int> se;

        for (auto &x : a)
        {
            cin >> x;
            se.insert(x);
            mp[x] = 1;
        }
        for (auto &x : b)
        {
            cin >> x;
            if (mp[x] == 1)
                mp[x] = 2;
            se.insert(x);
        }
        for (auto x : se)
        {
            cout << x << " ";
        }
        cout << endl;
        for (auto x : mp)
        {
            if (x.second == 2)
                cout << x.first << " ";
        }
        cout << endl;
    }
    return 0;
}