// Nguyen Huu Quang Hoa - B21DCCN379
#include <bits/stdc++.h>
using namespace std;

using ll = long long;

string s;
int n, ok;

vector<string> v;

void init()
{
    s = string(n, 'A');
}
void sinh()
{
    int i = n - 1;
    while (i >= 0 && s[i] == 'B')
    {
        s[i] = 'A';
        i--;
    }
    if (i == -1)
        ok = 0;
    else
        s[i] = 'B';
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    for (int i = 1; i <= 10; i++)
    {
        n = i;
        ok = 1;
        init();
        while (ok)
        {
            v.push_back(s);
            sinh();
        }
    }
    int t;
    cin >> t;
    while (t--)
    {
        int x;
        cin >> x;
        for (auto y : v)
        {
            if (y.size() == x)
                cout << y << " ";
            if (y.size() > x)
                break;
        }
        cout << endl;
    }
    return 0;
}