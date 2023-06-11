#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int n, k, a[1000001], ok = 1;

void init()
{
    for (int i = 1; i <= k; i++)
    {
        a[i] = 1;
    }
}

void sinh()
{
    int i = k;
    while (i >= 1 && a[i] == n)
        --i;
    if (i == 0)
        ok = 0;
    else
    {
        a[i]++;
        for (int j = i + 1; j <= k; j++)
        {
            a[j] = 1;
        }
    }
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n >> k;
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
    return 0;
}