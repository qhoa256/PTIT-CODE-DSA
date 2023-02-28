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
        pair<int, int> p[n];
        for (int i = 0; i < n; i++)
        {
            cin >> p[i].first >> p[i].second;
        }
        sort(p, p + n, [](pair<int, int> a, pair<int, int> b) -> bool
             { return a.second < b.second; });
        int ans = 1;
        int tmp = p[0].second;
        for (int i = 1; i < n; i++)
        {
            if (tmp <= p[i].first)
            {
                ans++;
                tmp = p[i].second;
            }
        }
        cout << ans << endl;
    }
    return 0;
}