// Nguyen Huu Quang Hoa - B21DCCN379
#include <bits/stdc++.h>
using namespace std;

using ll = long long;

string s;

void gray2()
{
    cout << s[0];
    for (int i = 1; i < s.size(); i++)
    {
        if (s[i] == s[i - 1])
            cout << 0;
        else
            cout << 1;
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
        cin >> s;
        gray2();
        cout << endl;
    }
    return 0;
}