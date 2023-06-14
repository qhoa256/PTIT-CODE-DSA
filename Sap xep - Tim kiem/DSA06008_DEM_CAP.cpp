#include <bits/stdc++.h>
#pragma gcc optimize("Ofast")
#define endl '\n'
using namespace std;

using ll = long long;

/*
- Đề bài: Cho mảng X[] gồm n phần tử và mảng Y[] gồm m phần tử. Hãy đếm số các cặp x^y > y^x, trong đó x€X[] và y€Y[].
Ví dụ X[] = {2, 1, 6 }, Y[] = {1, 5} ta có kết quả là 3 cặp (2, 1), (2, 5), (6, 1).

Input:
1
3 2
2 1 6
1 5
Output:
3

Kiến thức:
    + Nếu x < y thì x^y > y^x trừ các cặp (2, 3) và (2, 4)
    + Ngoại lệ x > y thì x^y > y^x đó là Trường hợp:
        - (3, 2) vì 3 > 2 nên 3^2 > 2^3
*/

// Hàm tìm vị trí đầu tiên > x trong mảng đã được sort.
int upper(int a[], int l, int r, int x)
{
	int res = -1;
	while (l <= r)
	{
		int m = (l + r) / 2;
		if (a[m] > x)
		{
			res = m;
			// Tìm về phía trước xem có phần tử ở vị trí trước nữa mà còn > x hay không.
			r = m - 1;
		}
		// Nếu nhỏ hơn thì phải tìm sang bên phải để tìm được ptu > x.
		else
		{
			l = m + 1;
		}
	}
	return res;
}

// mảng này để đến tần xuất của các phần tử < 5.
// vì các trường hợp ngoại lệ toàn các cặp số có giá trị < 5.
int cnt[5];

int dem(int y[], int m, int x)
{
	// Nếu x == 0 thì sẽ không có phần tử trong mảng y[] thỏa mãn điều
	if (x == 0)
		return 0;

	// Nếu x == 1 thì chỉ có các cặp (1, 0) thỏa mãn.
	else if (x == 1)
		return cnt[0];

	// Còn lại thì các phần tử 0, 1 trong mảng y khi kết hợp với phần tử
	// x > 1 trong mảng a sẽ tạo ra các cặp thỏa mãn.
	int ans = cnt[0] + cnt[1];

	// Tìm vị trí đầu tiên trong mảng y mà > x.
	int i1 = upper(y, 0, m - 1, x);

	// Nếu tìm được chỉ số đầu tiên mà > x thì số phần tử thỏa mãn là m - (chỉ số đó).
	if (i1 != -1)
		ans += m - i1;

	// Nếu x == 2 thì sẽ trừ đi các trường hợp ngoại lệ chính là các cặp (2, 3) và (2, 4).
	if (x == 2)
		ans = ans - cnt[3] - cnt[4];

	// Và thêm cả cặp (3, 2) nữa vì cặp (3, 2) là cặp duy nhất mà x > y và x^y > y^x.
	if (x == 3)
		ans += cnt[2];
	return ans;
}

void solve()
{
	int n, m;
	cin >> n >> m;
	memset(cnt, 0, sizeof(cnt));
	int x[n], y[m];
	for (int i = 0; i < n; i++)
	{
		cin >> x[i];
	}
	for (int i = 0; i < m; i++)
	{
		cin >> y[i];
		if (y[i] <= 4)
		{
			cnt[y[i]]++;
		}
	}
	sort(y, y + m);
	ll ans = 0;
	for (int i = 0; i < n; i++)
	{
		// Cộng kết quả tìm kiếm cho từng x[i] đối với mảng y[].
		ans += dem(y, m, x[i]);
	}
	cout << ans << endl;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}