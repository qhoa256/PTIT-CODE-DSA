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
        int a[n], b[n];
        for (int i = 0; i < n; i++)
        {
            cin >> b[i];
            a[i] = i + 1;
        }
        vector<vector<int>> v;
        do
        {
            vector<int> tmp(a, a + n);
            v.push_back(tmp);
        } while (next_permutation(a, a + n));
        for (int i = 0; i < v.size(); i++)
        {
            int ok = 1;
            for (int j = 0; j < v[i].size(); j++)
            {
                if (b[j] != v[i][j])
                {
                    ok = 0;
                    break;
                }
            }
            if (ok)
            {
                cout << i + 1 << endl;
                break;
            }
        }
    }
    return 0;
}