// Nguyen Huu Quang Hoa - B21DCCN379
#include <bits/stdc++.h>
using namespace std;

using ll = long long;

string s;
int n, ok = 1;

void init()
{
    s = string(n, '6');
}

void sinh()
{
    int i = n - 1;
    while (i >= 0 && s[i] == '8')
    {
        s[i] = '6';
        --i;
    }
    if (i == -1)
        ok = 0;
    else
        s[i] = '8';
}
bool check3()
{
    int cnt = 0;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '6')
            cnt++;
        else
        {
            if (cnt > 3)
                return false;
            cnt = 0;
        }
    }
    return cnt <= 3;
}
bool check2()
{
    return s[0] == '8' && s[s.size() - 1] == '6';
}
bool check1()
{
    if (s.size() < 6)
        return false;
    for (int i = 0; i < s.size() - 1; i++)
    {
        if (s[i] == '8' && s[i + 1] == '8')
            return false;
    }
    return true;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n;
    init();
    while (ok)
    {
        if (check1() && check2() && check3())
            cout << s << endl;
        sinh();
    }
    return 0;
}