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
        int ok = 0;
        int n, k;
        cin >> n >> k;
        int a[n];
        for (auto &x : a)
        {
            cin >> x;
        }
        sort(a, a + n);
        for (int i = 0; i < n; i++)
        {
            int sum = a[i];
            int l = i + 1, r = n - 1;
            while (l < r)
            {
                if (a[l] + a[r] + sum == k)
                {
                    ok = 1;
                    break;
                }
                else if (a[l] + a[r] + sum < k)
                {
                    l++;
                }
                else
                {
                    r--;
                }
            }
        }
        if (ok)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    return 0;
}