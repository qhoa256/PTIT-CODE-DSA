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
        ll a[n], b[n];
        for (auto &x : a)
        {
            cin >> x;
        }
        for (auto &x : b)
        {
            cin >> x;
        }
        sort(a, a + n);
        sort(b, b + n, greater<ll>());
        ll ans = 0;
        for (int i = 0; i < n; i++)
        {
            ans += a[i] * b[i];
        }
        cout << ans << endl;
    }
    return 0;
}