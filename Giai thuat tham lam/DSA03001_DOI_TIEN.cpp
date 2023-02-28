// Nguyen Huu Quang Hoa - B21DCCN379
#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int coin[10] = {1, 2, 5, 10, 20, 50, 100, 200, 500, 1000};
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int ans = 0;
        int i = 9;
        while (n)
        {
            ans += n / coin[i];
            n = n % coin[i];
            --i;
        }
        cout << ans << endl;
    }
    return 0;
}