// Nguyen Huu Quang Hoa - B21DCCN379
#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int n, x;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
    {
        cin >> n >> x;
        int a[n];
        for (auto &x : a)
        {
            cin >> x;
        }
        stable_sort(a, a + n, [](int a, int b) -> bool
                    { return abs(x - a) < abs(x - b); });
        for (auto x : a)
        {
            cout << x << " ";
        }
        cout << endl;
    }
    return 0;
}