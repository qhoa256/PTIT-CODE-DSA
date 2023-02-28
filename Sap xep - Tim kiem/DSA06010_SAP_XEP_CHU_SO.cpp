#include <bits/stdc++.h>

using namespace std;
set<int> s;

void check(int n)
{
    while (n > 0)
    {
        s.insert(n % 10);
        n /= 10;
    }
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            check(a[i]);
        }
        for (int i : s)
        {
            cout << i << " ";
        }
        cout << endl;
        s.clear();
    }
}