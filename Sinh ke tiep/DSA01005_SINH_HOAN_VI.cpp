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
        for (int i = 0; i < n; i++)
        {
            a[i] = i + 1;
        }
        do
        {
            for (int i = 0; i < n; i++)
            {
                cout << a[i];
            }
            cout << " ";
        } while (next_permutation(a, a + n));
        cout << endl;
    }
    return 0;
}