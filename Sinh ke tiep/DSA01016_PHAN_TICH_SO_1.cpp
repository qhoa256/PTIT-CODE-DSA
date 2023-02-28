// Nguyen Huu Quang Hoa - B21DCCN379
#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int t, n, a[1005], cnt, ok;

void init()
{
    a[1] = n;
}

void sinh()
{
    int i = cnt;
    while (i >= 1 && a[i] == 1)
        --i;
    if (i == 0)
        ok = 0;
    else
    {
        a[i]--;
        int tmp = cnt - i + 1;
        cnt = i;
        int q = tmp / a[i];
        int r = tmp % a[i];
        if (q)
        {
            for (int j = 1; j <= q; j++)
            {
                a[++cnt] = a[i];
            }
        }
        if (r)
            a[++cnt] = r;
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
        cin >> n;
        cnt = 1, ok = 1;
        init();
        while (ok)
        {
            cout << "(";
            for (int i = 1; i <= cnt; i++)
            {
                cout << a[i];
                if (i != cnt)
                    cout << " ";
            }
            cout << ") ";
            sinh();
        }
        cout<<endl;
    }
    return 0;
}