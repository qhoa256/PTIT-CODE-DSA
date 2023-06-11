#include<bits/stdc++.h>
using namespace std;

int main(){
	int t;
	cin>>t;
	cin.ignore();
	while(t--){
		string s;
		getline(cin,s);
		stringstream ss(s);
		string tmp;
		stack<string>st;
		while(ss>>tmp){
			st.push(tmp);
		}
		while(!st.empty()){
			cout<<st.top()<<" ";
			st.pop();
		}
		cout<<endl;
	}
	return 0;
}
/*
2
I like this program very much
much very program this like I
*/
