// Nguyen Huu Quang Hoa - B21DCCN379
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
int t, n, k, ok;
char a[1005];

void init()
{
    for (int i = 1; i <= k; i++)
    {
        a[i] = char('A' + i - 1);
    }
}

void sinh()
{
    int i = k;
    while (i >= 1 && a[i] == char('A' + n - k + i - 1))
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
    int t;
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
            cout << endl;
            sinh();
        }
    }
    return 0;
}