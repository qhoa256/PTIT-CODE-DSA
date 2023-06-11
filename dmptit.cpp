#include<bits/stdc++.h>
using namespace std;
using ll=long long;

void right(int a[],int n,int d[]){
	stack<int>st;
	for(int i=0;i<n;i++){
		while(!st.empty() && a[i]<a[st.top()]){
			d[st.top()]=i;
			st.pop();
		}
		st.push(i);
	}
	while(!st.empty()){
		d[st.top()]=n;
		st.pop();
	}
}

void left(int a[],int n,int d[]){
	stack<int>st;
	for(int i=n-1;i>=0;i--){
		while(!st.empty() && a[i]<a[st.top()]){
			d[st.top()]=i;
			st.pop();
		}
		st.push(i);
	}
	while(!st.empty()){
		d[st.top()]=-1;
		st.pop();
	}
}
int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int a[n];
		for(auto &x:a) cin>>x;
		int l[n]={0},r[n]={0};
		left(a,n,l);
		right(a,n,r);
		ll res=0;
		for(int i=0;i<n;i++){
		   	ll tmp=1ll*a[i]*(r[i]-l[i]-1);
		   	res=max(res,tmp);
		}
		cout<<res<<endl;
	}
	return 0;
}