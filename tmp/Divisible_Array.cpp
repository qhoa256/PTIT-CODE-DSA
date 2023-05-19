#include<bits/stdc++.h>
using namespace std;
int main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		int a[n + 1];
		int tong = 0;
		a[n] = n;
		for (int i = 1; i <= n - 1; i++) a[i] = i;
		if ((n - 1) % 2 == 1) {
			int i = 1;
			while (((n / 2)*i ) % n != 0 || (n / 2)  *i <= 200) i++;
			a[n / 2] = n / 2 * i;
		}
		for (int i = 1; i <= n; i++) cout << a[i] << " ";
		cout << endl;
	}
}