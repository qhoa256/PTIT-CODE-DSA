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
        int n, k;
        cin >> n >> k;
        int a[n];
        for (auto &x : a)
        {
            cin >> x;
        }
        sort(a, a + n);
        ll ans = 0;
        for (int i = 0; i < n; i++)
        {
            auto it1 = lower_bound(a + i + 1, a + n, k - a[i]);
            auto it2 = upper_bound(a + i + 1, a + n, k - a[i]);
            ans += it2 - it1;
        }
        cout << ans << endl;
    }
    return 0;
}