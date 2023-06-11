#include<bits/stdc++.h>
using namespace std;

void solve(string s,int k){
	stack<int>st;
	int d[10005]={0};
	for(int i=0;i<s.size();i++){
		if(!st.empty() && s[i]==s[st.top()]){
			d[i]=d[st.top()]+1;
		}else{
			d[i]=1;
		}
		st.push(i);
		if(d[i]==k){
			for(int j=0;j<k;j++){
				st.pop();
			}
		}
	}
	if(st.empty()) cout<<"EMPTY\n";
	else{
		vector<int>v;
		while(!st.empty()){
			v.push_back(st.top());
			st.pop();
		}
		for(int i=v.size()-1;i>=0;i--){
			cout<<s[v[i]];
		}
	}
}
int main(){
	string s;
	cin>>s;
	int k;
	cin>>k;
	solve(s,k);
	return 0;
}
