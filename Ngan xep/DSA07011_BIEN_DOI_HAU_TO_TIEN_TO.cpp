#include<bits/stdc++.h>
using namespace std;

int main(){
	int t;
	cin>>t;
	while(t--){
		string s;
		cin>>s;
		stack<string>st;
		for(int i=0;i<s.size();i++){
			if(isalpha(s[i])){
				st.push(string(1,s[i]));
			}else{
				auto x=st.top(); st.pop();
				auto y=st.top(); st.pop();
				st.push(s[i]+y+x);
			}
		}
		cout<<st.top()<<endl;
	}
	return 0;
}
