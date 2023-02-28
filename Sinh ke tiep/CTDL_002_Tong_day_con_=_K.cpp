// Nguyen Huu Quang Hoa - B21DCCN379
#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int a[1001], b[1001], n, ok = 1, k;

void init()
{
    for (int i = 1; i <= n; i++)
    {
        a[i] = 0;
    }
}

void sinh()
{
    int i = n;
    while (i >= 1 && a[i] == 1)
    {
        a[i] = 0;
        i--;
    }
    if (i == 0)
        ok = 0;
    else
        a[i] = 1;
}

bool check()
{
    int sum = 0;
    for (int i = 1; i <= n; i++)
    {
        if (a[i])
            sum += b[i];
    }
    return sum == k;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
    {
        cin >> b[i];
    }
    vector<vector<int>> v;
    int res = 0;
    init();
    while (ok)
    {
        if (check())
        {
            res++;
            for (int i = 1; i <= n; i++)
            {
                if (a[i])
                    cout << b[i] << " ";
            }
            cout<<endl;
        }
        sinh();
    }
    cout << res;
    return 0;
}