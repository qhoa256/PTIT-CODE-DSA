#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long n, k;
        cin >> n;
        long long a[n];
        map<long long, long long> m;
        long long max1 = INT_MIN;
        for (long long i = 0; i < n; i++)
        {
            cin >> a[i];
            m[a[i]]++;
        }
        long long ok = 0;
        for (long long i = 0; i < n; i++)
        {
            if (m[a[i]] > 1)
            {
                ok = a[i];
                break;
            }
        }
        if (ok)
            cout << ok << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}