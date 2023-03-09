#include <bits/stdc++.h>

using namespace std;

using ll = long long;

bool binary_search(vector<ll> v, ll l, ll r, ll x)
{
    while (l <= r)
    {
        ll m = (l + r) / 2;
        if (v[m] == x)
            return true;
        ++l;
        --r;
    }
    return false;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ifstream in;
    in.open("Data.txt");
    if (in.is_open())
    {
        string s;
        stringstream ss(s);
        string tmp;
        vector<ll> v;
        while (ss >> tmp)
        {
            v.push_back(stoll(tmp));
        }
        for (int i = 0; i < v.size(); i++)
        {
            for (int j = 0; j < v.size() - i; j++)
            {
                if (v[j] > v[j + 1])
                {
                    swap(v[j], v[j + 1]);
                }
            }
            for (int i = 0; i < v.size(); i++)
            {
                cout << v[i] << " ";
            }
        }
        ll x;
        cin >> x;
        if (binary_search(v, 0, v.size() - 1, x))
            cout << "YES";
        else
            cout << "NO";
    }
    return 0;
}