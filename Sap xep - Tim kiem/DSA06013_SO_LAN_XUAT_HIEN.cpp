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
        int n, x;
        cin >> n >> x;
        int a[n];
        map<int, int> mp;
        for (auto &x : a)
        {
            cin >> x;
            mp[x]++;
        }
        if (mp[x] == 0)
            cout << -1 << endl;
        else
            cout << mp[x] << endl;
    }
    return 0;
}