// Nguyen Huu Quang Hoa - B21DCCN379
#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    string s1, s2;
    cin >> s1 >> s2;
    string s3 = s1, s4 = s2;
    for (int i = 0; i < s1.size(); i++)
    {
        if (s1[i] == '6')
            s1[i] = '5';
    }
    for (int i = 0; i < s2.size(); i++)
    {
        if (s2[i] == '6')
            s2[i] = '5';
    }
    cout << stoll(s1) + stoll(s2) << " ";
    for (int i = 0; i < s3.size(); i++)
    {
        if (s3[i] == '5')
            s3[i] = '6';
    }
    for (int i = 0; i < s4.size(); i++)
    {
        if (s4[i] == '5')
            s4[i] = '6';
    }
    cout << stoll(s3) + stoll(s4);
    return 0;
}