#include <bits/stdc++.h>
using namespace std;
int kq[5000];
int dk = 0;
int dem;
vector <string> ans;

void Try(int k, int n) {
	for (int i = 0; i <= 2; i++) {
		kq[k] = i;
		if (i == 2) {
			dk++;
		}
		if (k == n) {
			if (kq[1] != 0 && dk > n / 2) {
				dem++;
				string s;
				for (int j = 1; j <= n; j++) {
					s += to_string(kq[j]);
				}
				ans.push_back(s);
			}
		}
		else {
			Try(k + 1, n);
		}
		if (i == 2) {
			dk--;
		}
	}
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		dem = 0;
		int i = 1;
		while (dem < n) {
			Try(1, i);
			i++;
		}
		for (int i = 0; i < n ; i++) {
			cout << ans[i] << " ";
		}
		cout << endl;
		ans.clear();
	}
}
