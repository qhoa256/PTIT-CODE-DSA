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
        int l = 0, r = n - 1;
        for (int i = 0; i < n; i++)
        {
            if (!(i % 2))
            {
                cout << a[r] << " ";
                r--;
            }
            else
            {
                cout << a[l] << " ";
                l++;
            }
        }
        cout << endl;
    }
    return 0;
}