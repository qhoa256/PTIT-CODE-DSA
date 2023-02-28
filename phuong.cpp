#include <bits/stdc++.h>
using namespace std;

using ll = long long;
int n; string a[25], x[25];
int min_val = 1e9, used[25];

int solve(string s, string t)
{
  int dem = 0;
  for (int i = 0; i < s.size(); ++i)
  {
    for (int j = 0; j < t.size(); ++j)
    {
      if (s[i] == t[j])
      {
        ++dem; break;
      }
    }
  }
  return dem;
}

void Try(int i, int cnt)
{
  if (cnt >= min_val) return;
  for (int j = 1; j <= n; ++j)
  {
    if (!used[j])
    {
      x[i] = a[j];
      used[j] = 1;
      if (i == n)
      {
        min_val = min(min_val, cnt + solve(x[i - 1], x[i]));
      }
      else Try(i + 1, cnt + solve(x[i - 1], x[i]));
      used[j] = 0;
    }
  }
}

int main(int argc, char **argv)
{
  cin >> n;
  for (int i = 1; i <= n; ++i) cin >> a[i];
  x[0] = "";
  Try(1, 0);
  cout << min_val;
}