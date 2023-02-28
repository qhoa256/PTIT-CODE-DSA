#include <bits/stdc++.h>
using namespace std;

int n, k;
int a[30];
vector<string> tmp;

void print()
{
    for (int i = 1; i <= k; ++i)
    {
        cout << tmp[a[i]] << " ";
    }
    cout << endl;
}

void Try(int i)
{
    for (int j = a[i - 1] + 1; j <= n - k + i; j++)
    {
        a[i] = j;
        if (i == k)
            print();
        else
            Try(i + 1);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> k;
    set<string> se;
    tmp.push_back("");
    for (int i = 1; i <= n; ++i)
    {
        string s;
        cin >> s;
        se.insert(s);
    }
    for (auto it = se.begin(); it != se.end(); ++it)
    {
        tmp.push_back(*it);
    }
    n = tmp.size() - 1;
    sort(tmp.begin(), tmp.end());
    Try(1);
    return 0;
}