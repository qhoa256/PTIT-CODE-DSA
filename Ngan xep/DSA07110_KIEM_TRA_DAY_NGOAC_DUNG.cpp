#include<bits/stdc++.h>
using namespace std;

string s;
int t;
bool solve(){
	stack<char>st;
		for(int i=0;i<s.size();i++){
			if(s[i]=='[' || s[i]=='(' || s[i]=='{'){
				st.push(s[i]);
			}else{
				if(st.empty()) return false;
				if(!st.empty()){
				if(st.top()=='(' && s[i]==')') st.pop();
				else if(st.top()=='[' && s[i]==']') st.pop();
				else if(st.top()=='{' && s[i]=='}') st.pop();
				}
			}
		}
	if(st.empty()) return true;
	else return false;
}
int main(){
	cin>>t;
	while(t--){
		cin>>s;
		if(solve()) cout<<"YES\n";
		else cout<<"NO\n";
	}
	return 0;
}
/*
2
[()]{}{[()()]()}
[(])

YES
NO
*/
