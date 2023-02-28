// Nguyen Huu Quang Hoa - B21DCCN379
#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int a[1005], ok, n, k, t;

void init()
{
    for (int i = 1; i <= k; i++)
    {
        a[i] = i;
    }
}

void sinh()
{
    int i = k;
    while (i >= 1 && a[i] == n - k + i)
        --i;
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
        ok = 1;
        init();
        while (ok)
        {
            for (int i = 1; i <= k; i++)
            {
                cout << a[i];
            }
            cout << " ";
            sinh();
        }
        cout << endl;
    }
    return 0;
}