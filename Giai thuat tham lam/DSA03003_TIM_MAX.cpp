// Nguyen Huu Quang Hoa - B21DCCN379
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int mod = 1e9 + 7;
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
        int a[n];
        for (auto &x : a)
        {
            cin >> x;
        }
        sort(a, a + n);
        ll ans = 0;
        for (int i = 0; i < n; i++)
        {
            ans += 1ll * a[i] * i;
            ans %= mod;
        }
        cout << ans << endl;
    }
    return 0;
}