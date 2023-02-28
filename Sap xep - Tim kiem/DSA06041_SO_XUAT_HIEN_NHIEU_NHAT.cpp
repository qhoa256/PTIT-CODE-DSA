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
        int n;
        cin >> n;
        int ans = -1e9;
        int a[n];
        map<int, int> mp;
        for (auto &x : a)
        {
            cin >> x;
            mp[x]++;
            ans = max(ans, mp[x]);
        }
        if (ans <= n / 2)
            cout << "NO\n";
        else
        {
            for (auto x : mp)
            {
                if (x.second == ans)
                {
                    cout << x.first << endl;
                    break;
                }
            }
        }
    }
    return 0;
}