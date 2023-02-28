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
        int a[n];
        for (auto &x : a)
        {
            cin >> x;
        }
        sort(a, a + n);
        int ans = INT_MAX;
        for (int i = 1; i < n; i++)
        {
            ans = min(ans, a[i] - a[i - 1]);
        }
        cout << ans << endl;
    }
    return 0;
}