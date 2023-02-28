// Nguyen Huu Quang Hoa - B21DCCN379
#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int n, t, a[1005], ok, k;

void sinh()
{
    int i = k;
    while (i >= 1 && a[i] == n - k + i)
    {
        --i;
    }
    if (i == 0)
        ok = 0;
    else
    {
        a[i]++;
        for (int j = i + 1; j <= k; j++)
        {
            a[j] = a[j - 1] + 1;
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> t;
    while (t--)
    {
        cin >> n >> k;
        for (int i = 1; i <= k; i++)
        {
            cin >> a[i];
        }
        ok = 1;
        sinh();
        if (!ok)
        {
            for (int i = 1; i <= k; i++)
            {
                cout << i << " ";
            }
        }
        else
        {
            for (int i = 1; i <= k; i++)
            {
                cout << a[i] << " ";
            }
        }
        cout << endl;
    }
    return 0;
}