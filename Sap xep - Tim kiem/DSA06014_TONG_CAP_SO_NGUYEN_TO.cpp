// Nguyen Huu Quang Hoa - B21DCCN379
#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int p = 1e6;
int prime[p + 1];

void sieve()
{
    for (int i = 0; i <= p; i++)
    {
        prime[i] = 1;
    }
    prime[0] = prime[1] = 0;
    for (int i = 2; i <= sqrt(p); i++)
    {
        if (prime[i])
        {
            for (int j = i * i; j <= p; j += i)
            {
                prime[j] = 0;
            }
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    sieve();
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int ok = 0;
        for (int i = 2; i <= n; i++)
        {
            if (prime[i] && prime[n - i])
            {
                cout << i << " " << n - i << endl;
                ok = 1;
                break;
            }
        }
        if (!ok)
            cout << -1 << endl;
    }
    return 0;
}