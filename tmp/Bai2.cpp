Tiến Thắng
#include<bits/stdc++.h>
using namespace std;
bool cmp(pair<int,int> a, pair<int,int> b){
	return a.second<b.second;
}
int main(){
	int t;
	cin>>t;
	while(t--){
		int n,k;
		cin>>n>>k;
		pair<int,int>  a[n+1];
		int b[n+1];
		for(int i=0; i<n; i++) {
			cin>>a[i].first; a[i].second=i;}
		for(int i=0; i<n; i++) cin>>b[i];
		sort(a,a+n);
		sort(b,b+n);
		for(int i=0; i<n; i++) {
			a[i].first=b[i];
		}
		sort(a,a+n,cmp);
		for(int i=0; i<n; i++){
			cout<<a[i].first<<" ";
		}
		cout<<endl;
	}
}