#include <bits/stdc++.h>

using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int a[n];
        vector<int> v;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            v.push_back(a[i]);
        }
        int start = 0, end = 0;
        sort(v.begin(), v.end());
        for (int i = 0; i < n; i++)
        {
            if (a[i] != v[i])
            {
                start = i + 1;
                break;
            }
        }
        for (int i = n - 1; i >= 0; i--)
        {
            if (a[i] != v[i])
            {
                end = i + 1;
                break;
            }
        }
        cout << start << " " << end << endl;
    }
    return 0;
}