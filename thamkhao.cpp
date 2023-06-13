#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define pii pair<int, int>
#define ft first
#define sd second



int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int test = 1;
	cin >> test;
	while(test--){
		int n;
		cin >> n;
		int a[n];
		for(int &x : a)
			cin >> x;
		int cnt = 0;
		for (int i = 0; i < n - 1; ++i){
			int tmp = a[i], idx = 0;
			for (int j = i + 1; j < n; ++j){
				if(a[j] < tmp){
					tmp = a[j];
					idx = j;
				}
			}
			if(tmp < a[i]){
				++cnt;
				swap(a[idx], a[i]);
			}
		}
		cout << cnt << "\n";
	}
}