#include<bits/stdc++.h>
using namespace std;
using ll=long long;

int main(){
	int t;
	cin>>t;
	while(t--){
		string s;
		cin>>s;
		stack<string>st;
		for(int i=s.size()-1;i>=0;i--){
			if(isalpha(s[i])){
				st.push(string(1,s[i]));
			}else{
				string tmp="";
				string x=st.top();
				st.pop();
				string y=st.top();
				st.pop();
				tmp+="("+x+s[i]+y+")";
				st.push(tmp);
			}
		}
		cout<<st.top()<<endl;
	}
}

/*
2
*+AB-CD
*-A/BC-/AKL

((A+B)*(C-D))
((A-(B/C))*((A/K)-L)
*/
