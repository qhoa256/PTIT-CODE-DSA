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
        int stt;
        cin >> stt;
        string s;
        cin >> s;
        if (!next_permutation(s.begin(), s.end()))
            cout << stt << " BIGGEST\n";
        else
        {
            cout << stt << " " << s << endl;
        }
    }
    return 0;
}